/* This was is an oops program based on an homework question given by derek banas in his video on C++ OOPS. This is for my practice purposes and thanks to derek banas for his tutorial videos */


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

class Warrior{
	private:
		const char *m_heroname;
		int m_health;
		int m_attack;
		int m_block;

	public:
		Warrior(const char *hero,int health,int attack,int block):m_heroname(hero),m_health(health),m_attack(attack),m_block(block){
		
		}
		Warrior():m_heroname(NULL),m_health(0),m_attack(0),m_block(0){
		
		
		}

		int getHealth();
		int getAttack();
		int getBlock();
		const char* getHeroName();
		void setHealth(int);
};

class Battle:public Warrior{

	public:
		Battle(){
			
			cout<<"Let the battle begin"<<endl;
		}

		void beginBattle(Warrior&,Warrior&);
		void winner(Warrior&,Warrior&);
};

int Warrior::getHealth(){
	return m_health;
}
int Warrior::getAttack(){
	return m_attack;
}
int Warrior::getBlock(){
	return m_block;
}
const char* Warrior::getHeroName(){
	return m_heroname;
}
void Warrior::setHealth(int h){
	this->m_health=h;
}
void Battle::beginBattle(Warrior& w1,Warrior& w2){
	
	int health_one=w1.getHealth();
	int health_two=w2.getHealth();
	int block_one=w1.getBlock();
	int block_two=w2.getBlock();
	int attack_one=w1.getAttack();
	int attack_two=w2.getAttack();

	while(w1.getHealth()>0 && w2.getHealth()>0){

		if(attack_one>block_one){
			int temp=attack_one-block_one;
			health_one=health_one-temp;
			w1.setHealth(health_one);
		}else if(attack_one<=block_one){
			int temp=0;
			health_one=health_one-temp;
			w1.setHealth(health_one);
		}
		if(attack_two>block_two){
			int temp=attack_two-block_two;
			health_two=health_two-temp;
			w2.setHealth(health_two);

		}else if(attack_two<=block_two){
			int temp=0;
			health_two=health_two-temp;
			w2.setHealth(health_two);
		}
	}
		
		winner(w1,w2);
	
}
void Battle::winner(Warrior& w1,Warrior& w2){
	int health_one=w1.getHealth();
	int health_two=w2.getHealth();
	int min_val=min(health_one,health_two);
	if(min_val==health_one){
		cout<<"Warrior: "<<w2.getHeroName()<<" Won";
	}else if(min_val==health_two){
		cout<<"Warrior: "<<w1.getHeroName()<<" Won";
	}
}

int main(int argc,char* argv[]){
	srand(time(NULL));
	Battle b;
	Warrior thor("Thor",100,30,15);
	Warrior hulk("Hulk",135,25,10);
	b.beginBattle(thor,hulk);
	return(0);
}

















