#include <iostream>
#include <string>
using namespace std;


//////QUACK
class IQuackStrategy
{
public:
    virtual void Quack()=0;
};
class NormalQuack : public IQuackStrategy {
public:void Quack() override
{
    cout << "Quack :v" << endl;
}
};
class SquiqQuack : public IQuackStrategy {
public:void Quack() override
{
    cout << "squiq ><" << endl;
}
};
class SilenQuack : public IQuackStrategy {
public:void Quack() override
{
    cout << "" << endl;
}
};
///SWIM
class ISwimStrategy
{
public:
    virtual void Swim() = 0;
};
class NormalSwim :public ISwimStrategy {
public: void Swim() override{ cout << "ANGRY Sswwiimm" << endl; }
};
class CuteSwim :public ISwimStrategy {
public: void Swim() override { cout << "Cute Sswwiimm~" << endl; }
};
class No_Swim :public ISwimStrategy {
public: void Swim() override { cout << "" << endl; }
};
///FLY
class IFlyStrategy
{
public:
    virtual void Fly() = 0;
};
class CanFly :public IFlyStrategy {
public:void Fly() override { cout << "I can Fly!" << endl; }
};
class Can_not_Fly :public IFlyStrategy {
public:void Fly() override { cout << "I can`t Fly :( " << endl; }
};

/////////////////////////
class IDispley
{
private:
    string name;
public:

    IDispley(string name) {
        this->name = name;
    }

    void Print()
    {
        cout << name<<"-"<<endl;
    }
};
///////////////////////

class Duck
{
private:
    IQuackStrategy &quackStrategy;
    ISwimStrategy &swimStrategy;
    IFlyStrategy &flyStrategy;
        IDispley &displey;
public:
Duck(IDispley &disp, IQuackStrategy &quack,ISwimStrategy &swim,IFlyStrategy &fly) : displey(disp), quackStrategy(quack), swimStrategy(swim),flyStrategy(fly){}
    void Print() {displey.Print();}
    void Quack() { quackStrategy.Quack(); }
    void Swim() { swimStrategy.Swim(); }
    void Fly() { flyStrategy.Fly(); }
};

void TestDuck(Duck& duck)
{
    duck.Print();
    duck.Quack();
    duck.Swim();
    duck.Fly();
}

int main()
{
    Duck  MarlladDuck = *new Duck(*new IDispley("Marllad"), *new NormalQuack(),*new NormalSwim(),*new CanFly());
    Duck SilentDuck = *new Duck(*new IDispley("Silent"), *new SilenQuack(), *new CuteSwim(), *new CanFly());
    Duck RubberDuck = *new Duck(*new IDispley("Rubber"), *new SquiqQuack(), *new CuteSwim(), *new Can_not_Fly());
    Duck StoneDuck = *new Duck(*new IDispley("Stone"), *new  SilenQuack(), *new No_Swim(), *new Can_not_Fly());
    TestDuck(MarlladDuck);
    TestDuck(SilentDuck);
    TestDuck(RubberDuck);
    TestDuck(StoneDuck);
    return 0;
}
