// a great use case for unions is when creating structs.
// For example, if we have some optional fields in such structs
// it could be a waste of space to have both in the struct.
// But using unions we can ensure that, we can use just one of them
// and it is a log more efficient in memory, cuz we don't need to
// allocate the space for both anymore, just for the greatest one.

#include <stdbool.h>
#include <stdio.h>

// a struct to represent a fictional user, that can be either a robot
// or a person. If it's a robot, it supposed to have an firmware_version and
// if it's a person, it should have a personality field. So, without the union
// we'll need to waste memory allocation both, the firmware_version and
// personality fields.

typedef struct player {
  char *name;
  bool is_robot;
  union {
    int firmware_version;
    char *personality;
  };
} Player;

void display_player(Player *player);

int main(int argc, char *argv[]) {
  Player p1, p2;

  // p1 is a person
  p1.is_robot = false;
  p1.name = "Kevin";
  p1.personality = "Introspective";

  // p2 is a robot
  p2.is_robot = true;
  p2.name = "D351DA";
  p2.firmware_version = 1;

  display_player(&p1);
  display_player(&p2);

  return 0;
}

void display_player(Player *player) {
  printf("name: %s\n", player->name);

  if (player->is_robot) {
    printf("firmware_version: %d\n", player->firmware_version);
    return;
  }

  printf("personality: %s\n", player->personality);
}
