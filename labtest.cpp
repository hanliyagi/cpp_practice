#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	// 캐릭터 설정 함수
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	// 공격 함수
	virtual int attack() { return 0; }
	// 방어 함수
	virtual void defense(int _attack_point) { }
	// 캐릭터 정보 출력 함수
	virtual void print_info() { }
protected:
	string name;		// 캐릭터 이름
	int attack_point;	// 공격력
	int defense_point;	// 방어력
	int health;		// 체력
};

class Character : public Avengers {
public:
	Character() {
		srand((unsigned int)time(NULL));
		int random = rand() % 3;
		switch (random) {
		case 0:
			name = "IronMan";
			attack_point = 70;
			defense_point = 40;
			health = 100;
			break;
		case 1:
			name = "CaptainAmerica";
			attack_point = 60;
			defense_point = 50;
			health = 100;
			break;
		case 2:
			name = "Thor";
			attack_point = 80;
			defense_point = 30;
			health = 100;
			break;
		}
	}

	Character(string character) {
		if (character == "IronMan") {
			name = "IronMan";
			attack_point = 70;
			defense_point = 40;
			health = 100;
		}
		else if (character == "CaptainAmerica") {
			name = "CaptainAmerica";
			attack_point = 60;
			defense_point = 50;
			health = 100;
		}
		else if (character == "Thor") {
			name = "Thor";
			attack_point = 80;
			defense_point = 30;
			health = 100;
		}
	}
	~Character() {}
	
	int attack() override {
		return attack_point;
	}

	void defense(int _attack_point) override {
		health += (defense_point - _attack_point);
		if (health < 0)
			health = 0;
	}

	void print_info() override {
		cout << "Name: " << name << endl;
		cout << "Attack_Point: " << attack_point << endl;
		cout << "Defense_Point: " << defense_point << endl;
		cout << "Health: " << health << endl;
	}
	int get_health() { return health; }
};

int main() {
	Character my_char;
	Character enemy_char;
	string MyChar;

	cout << "Choose your charactr(IronMan, CaptainAmerica, Thor): ";
	cin >> MyChar;

	cout << "--My Character--" << endl;
	my_char = Character(MyChar);
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t"
		<< "Enemy Life:" << enemy_char.get_health() << endl;

	while (1) {
		enemy_char.defense(my_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life:" << enemy_char.get_health() << endl;
		if (enemy_char.get_health() <= 0) {
			cout << "You Win!" << endl;
			return 0;
		}

		my_char.defense(enemy_char.attack());
		cout << "My Life: " << my_char.get_health() << "\t"
			<< "Enemy Life:" << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0) {
			cout << "You Lose!" << endl;
			return 0;
		}
	}

	return 0;
}

