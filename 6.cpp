#include <iostream>

using namespace std;

class Cinematograph
{
protected:
    string name;
    bool released;

    Cinematograph(string name, bool released) : name(name), released(released)
    {

    }

    void showBasicInfo()
    {
        cout << "Name - " << name << endl;
        cout << "Released - " << released << endl;
    }

public:
    virtual void showInfo() = 0;
};

class Creators : Cinematograph
{
protected:
    string producer, scenarist;

    Creators(string producer, string scenarist, string name, bool released) : Cinematograph(name, released), producer(producer), scenarist(scenarist)
    {

    }

public:
    void changeProducer(string producer)
    {
        this->producer = producer;
    }

    void changeScenarist(string scenarist)
    {
        this->scenarist = scenarist;
    }

    void release()
    {
        released = true;
    }

    void showInfo()
    {
        showBasicInfo();
        cout << "Producer - " << producer << endl;
        cout << "Scenarist - " << scenarist << endl;
    }
};

class Picture : Cinematograph
{
protected:
    unsigned long cost;
    string theme;

    Picture(unsigned long cost, string theme, string name, bool released) : Cinematograph(name, released), cost(cost), theme(theme)
    {

    }

public:
    void reduceCost(unsigned long cost)
    {
        if (cost <= this->cost) {
            this->cost -= cost;
        }
    }

    void increaseCost(unsigned long cost)
    {
        this->cost += cost;
    }

    void release()
    {
        released = true;
    }

    void showInfo()
    {
        showBasicInfo();
        cout << "Cost - " << cost << endl;
        cout << "Theme - " << theme << endl;
    }
};

class Cinema : public Picture, public Creators
{
private:
    unsigned int duration;
    unsigned short part;

public:
    Cinema(unsigned int duration, unsigned short part, unsigned long cost, string theme, string producer, string scenarist, string name, bool released)
        : Picture(cost, theme, name, released), Creators(producer, scenarist, name, released), duration(duration), part(part)
    {

    }

    void nextPart()
    {
        part++;
    }

    void release()
    {
        Picture::release();
        Creators::release();
    }

    void showFullInfo()
    {
        cout << "Cinema";
        Picture::showInfo();
        Creators::showInfo();
        cout << "Duration - " << duration << endl;
        cout << "Part - " << part << endl;
    }
};

int main()
{
    string producer, scenarist, name, theme;
    unsigned int duration;
    unsigned short part;
    unsigned long cost;
    bool released;

    cout << "Producer: ";
    cin >> producer;

    cout << "Scenarist: ";
    cin >> scenarist;

    cout << "Name: ";
    cin >> name;

    cout << "Theme: ";
    cin >> theme;

    cout << "Duration: ";
    cin >> duration;

    cout << "Part: ";
    cin >> part;

    cout << "Cost: ";
    cin >> cost;

    cout << "Is released: ";
    cin >> released;

    Cinema* cinema = new Cinema{ duration, part, cost, theme, producer, scenarist, name, released };
    cinema->showFullInfo();

    cinema->increaseCost(100);
    cinema->reduceCost(50);
    cinema->changeProducer("Billy Herrington");
    cinema->changeScenarist("Victor Sladki");
    cinema->release();
    cinema->nextPart();

    cout << endl;
    cinema->showFullInfo();

    delete cinema;

    return 0;
}