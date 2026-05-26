#include <iostream>
#include <memory>
#include <string>

struct Bread { virtual ~Bread() = default; virtual std::string Name() const = 0; };
struct Patty { virtual ~Patty() = default; virtual std::string Name() const = 0; };
struct Cheese { virtual ~Cheese() = default; virtual std::string Name() const = 0; };
struct Sauce { virtual ~Sauce() = default; virtual std::string Name() const = 0; };

struct LightBread : public Bread { std::string Name() const override { return "LightBread"; } };
struct SaltyBread : public Bread { std::string Name() const override { return "SaltyBread"; } };
struct BeefPatty : public Patty { std::string Name() const override { return "BeefPatty"; } };
struct PorkPatty : public Patty { std::string Name() const override { return "PorkPatty"; } };
struct MozzarellaCheese : public Cheese { std::string Name() const override { return "MozzarellaCheese"; } };
struct CheddarCheese : public Cheese { std::string Name() const override { return "CheddarCheese"; } };
struct GarlicSauce : public Sauce { std::string Name() const override { return "GarlicSauce"; } };
struct MustardSauce : public Sauce { std::string Name() const override { return "MustardSauce"; } };

class HamburgerFactory {
public:
    virtual ~HamburgerFactory() = default;
    virtual std::unique_ptr<Bread> MakeBread() const = 0;
    virtual std::unique_ptr<Patty> MakePatty() const = 0;
    virtual std::unique_ptr<Cheese> MakeCheese() const = 0;
    virtual std::unique_ptr<Sauce> MakeSauce() const = 0;
};

class BeefHamburgerFactory : public HamburgerFactory {
public:
    std::unique_ptr<Bread> MakeBread() const override { return std::make_unique<LightBread>(); }
    std::unique_ptr<Patty> MakePatty() const override { return std::make_unique<BeefPatty>(); }
    std::unique_ptr<Cheese> MakeCheese() const override { return std::make_unique<MozzarellaCheese>(); }
    std::unique_ptr<Sauce> MakeSauce() const override { return std::make_unique<GarlicSauce>(); }
};

int main() {
    BeefHamburgerFactory beef;
    std::cout << "Bread: " << beef.MakeBread()->Name() << std::endl;
    std::cout << "Patty: " << beef.MakePatty()->Name() << std::endl;
    return 0;
}
