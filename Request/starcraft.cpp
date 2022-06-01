#include <iostream>


using namespace std;


class BaseUnit {
protected:
    string _name;
    int _minerals;
    int _gases;
    int _hp;
    int _dmg;
    int _def;
    int _size;
    bool _isAlive;
    bool _canAttack;


    BaseUnit(string name,
        int minerals,
        int gases,
        int hp,
        int dmg,
        int def,
        int size,
        bool canAttack) : _name(name), _minerals(minerals), _gases(gases), _hp(hp), _dmg(dmg), _def(def), _size(size), _canAttack(canAttack), _isAlive(false) {
    }
public:
	
    virtual void attack(BaseUnit& unit) {
        if (this->_isAlive && this->_canAttack) {
            cout << this->_name << " attack" << endl;
            unit.getAttacked(this->_dmg);
        }

        else if (this->_canAttack) {
            cout << this->_name << " is not Alive" << endl;
        }

        else {
            cout << this->_name << " can not attack now" << endl;
        }

        cout << endl;
    };


	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	virtual void produce(int& minerals, int& gases, string answer) {
    	if (this->_minerals > minerals) {
            cout << "Not enough minerals." << endl;
	    }
		
        else if (this->_gases > gases) {
	        cout << "Insufficient vespene gas." << endl;
		}
	
	    else {
            cout << answer << endl;
			this->_isAlive = true;
	        minerals -= this->_minerals;
	        gases -= this->_gases;
	        cout << "Remaining resources: " << minerals << "mineral, " << gases << "gas." << endl;
    	}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	

    void getAttacked(int dmg) {
        if (this->_isAlive && this->_canAttack) {
            int damage = dmg - this->_def;
            if (dmg < 0) {
                dmg = 0;
            }
			
            this->_hp -= damage;

            if (this->_hp <= 0) {
                cout << this->_name << " die" << endl;
                this->_isAlive = false;
            }

            else {
                cout << this->_name << "'s hp: " << this->_hp << endl;
            }

        }

        else if (this->_canAttack) {
            cout << this->_name << " is already died." << endl;
        }

        else {
            cout << this->_name << " can not attacked now" << endl;
        }
    }



    string getName() {
        return _name;
    }



    int getSize() {
        return _size;
    }



    void setCanAttack(bool status) {
        this->_canAttack = status;
    }

};



class smallUnit : public BaseUnit {
public:
    smallUnit(string name,
        int minerals,
        int gases,
        int hp,
        int dmg,
        int def,
        bool canAttack) : BaseUnit(name, minerals, gases, hp, dmg, def, 1, canAttack) {}
};



class mediumUnit : public BaseUnit {
public:
    mediumUnit(string name,
        int minerals,
        int gases,
        int hp,
        int dmg,
        int def,
        bool canAttack) : BaseUnit(name, minerals, gases, hp, dmg, def, 2, canAttack) {}
};



class largeUnit : public BaseUnit {
public:
    largeUnit(string name,
        int minerals,
        int gases,
        int hp,
        int dmg,
        int def,
        bool canAttack) : BaseUnit(name, minerals, gases, hp, dmg, def, 4, canAttack) {}
};


class Marine : public smallUnit {
public:
    Marine() : smallUnit("Marine", 50, 0, 40, 6, 0, true) {
    }


    void attack(BaseUnit& unit) {
        if (this->_isAlive && this->_canAttack) {
            cout << this->_name << " attack" << endl;
            if (this->_hp > 10) {
                cout << this->_name << " use stimpack" << endl;
                this->_hp -= 10;
                unit.getAttacked(this->_dmg);
            }

            unit.getAttacked(this->_dmg);
        }

        else if (this->_canAttack) {
            cout << this->_name << " is not Alive" << endl;
        }

        else {
            cout << this->_name << " can not attack now" << endl;
        }

        cout << endl;
    }
};



class Tank : public largeUnit {
public:
    Tank() : largeUnit("Tank", 150, 50, 150, 30, 1, true) {
    }

};



class Zealot : public mediumUnit {
public:
    Zealot() : mediumUnit("Zealot", 100, 0, 160, 16, 1, true) {
    }


};



class Dragoon : public largeUnit {

public:

    Dragoon() : largeUnit("Dragoon", 125, 50, 180, 20, 1, true) {
		
    }
};



class Dropship : public largeUnit {
	
protected:
    BaseUnit* units[8] = { NULL, };
    int remainSize;
    int index;

public:
	
    Dropship() : largeUnit("Dropship", 100, 100, 150, 0, 1, false), remainSize(8), index(0) {

    };



    void load(BaseUnit& unit) {
        if (remainSize >= unit.getSize()) {
            units[index] = &unit;
            ++index;
            remainSize -= unit.getSize();
            cout << "dropship load " << unit.getName() << endl;
            cout << "empty: " << remainSize << endl;
            unit.setCanAttack(false);
            printStatus();
        }
		
        else {
            cout << "not enough empty slot" << endl;
        }
    }

    /*

    void load(smallUnit& unit) {

        if (remainSize >= 1) {

            units[index] = &unit;

            ++index;

            remainSize -= 1;

            cout << "dropship load " << unit.getName() << endl;

            cout << "empty: " << remainSize << endl;

            unit.setCanAttack(false);

            printStatus();

        }

        else {

            cout << "not enough empty slot" << endl;

        }

    }



    void load(mediumUnit& unit) {

        if (remainSize >= 2) {

            units[index] = &unit;

            ++index;

            remainSize -= 2;

            cout << "dropship load " << unit.getName() << endl;

            cout << "empty: " << remainSize << endl;

            unit.setCanAttack(false);

            printStatus();

        }

        else {

            cout << "not enough empty slot" << endl;

        }

    }



    void load(largeUnit& unit) {

        if (remainSize >= 4) {

            units[index] = &unit;

            ++index;

            remainSize -= 4;

            cout << "dropship load " << unit.getName() << endl;

            cout << "empty: " << remainSize << endl;

            unit.setCanAttack(false);

            printStatus();

        }

        else {

            cout << "not enough empty slot" << endl;

        }

    }

    */

    void drop() {
        for (int i = 0; i < index; i++) {
            cout << units[i]->getName() << " drop" << endl;
            units[i]->setCanAttack(true);
            units[i] = NULL;
        }

        remainSize = 8;
        index = 0;
    }



    void printStatus() {
        cout << "-----dropship-----" << endl;

        for (int i = 0; i < index; i++) {
            cout << units[i]->getName() << " ";
        }
        cout << endl << "-----dropship-----" << endl;
    }



    void attack(BaseUnit& unit) {
        cout << this->_name << " is not attackable unit" << endl;
    }
};



int main() {

    Marine marine;

    Tank tank;

    Zealot zealot;

    Dragoon dragoon;

    Dropship dropship;



    int mineral = 1000;

    int gas = 1000;

    marine.produce(mineral, gas, "You wanna piece of me, boy?");

    tank.produce(mineral, gas, "Ready to roll out!");

    zealot.produce(mineral, gas, "My life for Aiur!");

    dragoon.produce(mineral, gas, "I have returned!");

    dropship.produce(mineral, gas, "Can I take your order?" );


    //cout << endl;



    //dropship.load(zealot);

    //dropship.load(marine);
	return 0;
}