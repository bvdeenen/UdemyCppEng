#include <string>
#include <utility>

class AttackInterface
{
public:
    AttackInterface() = default;

    virtual ~AttackInterface() = default;

    virtual void attack() const = 0;
};

class Weapon : public AttackInterface
{
public:
    Weapon(std::string _name,
           const float _damage,
           const float _attack_speed,
           const bool _single_handed,
           const bool _dual_handed)
        : name(std::move(_name)), damage(_damage), attack_speed(_attack_speed),
          single_handed(_single_handed), dual_handed(_dual_handed){};
    ~Weapon() override = default;

    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] float get_damage() const;
    [[nodiscard]] float get_attack_speed() const;
    [[nodiscard]] bool get_single_handed() const;
    [[nodiscard]] bool get_dual_handed() const;

protected:
    std::string name;
    float damage;
    float attack_speed;
    bool single_handed;
    bool dual_handed;
};

class Axe : public Weapon
{
public:
    Axe(const std::string &_name,
        const float _damage,
        const float _attack_speed)
        : Weapon(_name, _damage, _attack_speed, true, false){};
    ~Axe() override = default;

    void attack() const final;
};

class Longbow : public Weapon
{
public:
    Longbow(const std::string &_name,
            const float _damage,
            const float _attack_speed)
        : Weapon(_name, _damage, _attack_speed, false, true){};
    ~Longbow() override = default;

    void attack() const final;
};
