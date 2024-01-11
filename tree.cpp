#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    std::string name;
    std::string price;

    Product(std::string name, std::string price)
        : name(name), price(price) {}
};

class Category {
public:
    std::string name;
    std::vector<Category> subcategories;
    std::vector<Product> products;

    Category(std::string name)
        : name(name) {}

    void add_subcategory(const Category& subcategory) {
        subcategories.push_back(subcategory);
    }

    void add_product(const Product& product) {
        products.push_back(product);
    }
};

void display_categories(const Category& category, int indent = 0) {
    std::cout << std::string(indent * 2, ' ') << category.name << std::endl;


    for (const auto& subcategory : category.subcategories) {
        display_categories(subcategory, indent + 1);
    }

    for (size_t i = 0; i < category.products.size(); ++i) {
        std::cout << std::string((indent + 1) * 2, ' ') << i + 1 << ". "
                  << category.products[i].name << " - Rp " << category.products[i].price << std::endl;
    }
}

int get_user_choice(size_t num_options) {
    int choice;
    do {
        std::cout << "Enter your choice (1-" << num_options << ", 0 to exit): ";
        std::cin >> choice;

        if (choice < 0 || choice > static_cast<int>(num_options)) {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice < 0 || choice > static_cast<int>(num_options));

    return choice;
}

void choose_category(const Category& category) {
    int choice;
    do {
        std::cout << "Pilih kategori anda:" << std::endl;
        display_categories(category);

        choice = get_user_choice(category.subcategories.size() + category.products.size());

        if (choice > 0 && choice <= static_cast<int>(category.subcategories.size())) {
            choose_category(category.subcategories[choice - 1]);
        } else if (choice > 0 && choice <= static_cast<int>(category.products.size())) {
            std::cout << "You selected: " << category.products[choice - 1].name<< " - Rp " << category.products[choice - 1].price << std::endl;
        }
    } while (choice != 0);
}

int main() {
    // Membuat pohon kategori untuk toko online
    Category electronic("Electronic");
    Category smartphone("1. Smartphone");
    Category laptop("2. Laptop");

    Product phone1("iPhone 15", "Rp 15.240.000" );
    Product phone2("Samsung Galaxy j2 prime", "2.000.000");
    Product laptop3("MSI GF36", "10.000.000");
    Product laptop4("MacBook Pro", "25.000.000");

    smartphone.add_product(phone1);
    smartphone.add_product(phone2);
    laptop.add_product(laptop3);
    laptop.add_product(laptop4);

    electronic.add_subcategory(smartphone);
    electronic.add_subcategory(laptop);

    // Menampilkan pilihan kategori dan produk
    std::cout << "WELLCOME Store xazz" << std::endl;
    choose_category(electronic);

    return 0;
}