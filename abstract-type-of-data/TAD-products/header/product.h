// exported type
typedef struct product Product;
// function that read product
void readProduct(Product *product);
// function that displays a product
void displayProduct(Product *product);
// function that releases an allocated product
void freeProduct(Product *product);
// function that creates an instance of a product
Product* createProduct();