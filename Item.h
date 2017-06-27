#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item();

    virtual int modifyStrength(const int& strn) const = 0;
    virtual int modifyStamina(const int & stam) const = 0;

    virtual char print() const;

    virtual ~Item();
private:
    const char sign = '*';
    
};

class ArmingSword : public Item {
public:
    ArmingSword();

    int modifyStrength(const int& strn) const override;
    int modifyStamina(const int& stam) const override;

    virtual ~ArmingSword();
private:
};

class GreatSword : public Item {
public:
    GreatSword();

    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~GreatSword();
private:
};

class Club : public Item {
public:
    Club();

    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~Club();
private:
};

class RapierNDagger : public Item {
public:
    RapierNDagger();

    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~RapierNDagger();
private:
};

class Gambeson : public Item {
public:
    Gambeson();
    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~Gambeson();
private:
};

class MailArmour : public Item {
public:
    MailArmour();
    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~MailArmour();
private:
};

class Shield : public Item {
public:
    Shield();
    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~Shield();
private:
};

class FullPlateArmour : public Item {
public:
    FullPlateArmour();

    int modifyStamina(const int& stam) const override;
    int modifyStrength(const int& strn) const override;

    virtual ~FullPlateArmour();
private:
};

#endif /* ITEM_H */

