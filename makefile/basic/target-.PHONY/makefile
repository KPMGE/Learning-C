# we can put our targets that not denpend of a file in the .PHONY target, 
# so, they'll be executed always


.PHONY: all say_hello generate
all: say_hello generate 

say_hello:
	@echo "Hello there!"

generate:
	@echo "Creating files..."
	@touch file-test.txt

clean:
	@echo "Cleaning up"
	@rm *.txt
