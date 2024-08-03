// Worked on by Parker Riggs //
#include "Product.h"
#include <string>
#include <cstdlib>

class Frame:public Product{
    public:
        // Constructor //
        Frame(){
            price = 9999.99;  // Default price of a frame
            material = "N/A";
            type = "N/A";
        }

        // Setters //
        void set_price(double newPrice);
        void set_material(std::string newMaterial);
        void set_type(std::string newType);

        // Getters //
        double get_price();
        std::string get_material();
        std::string get_type();

        void output(std::ostream& outs)const;
        void input(std::istream& ins);

    private:
        std::string material;
        std::string type;
};