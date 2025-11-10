#include <iostream>
using namespace std;

class Participant {
protected:
    string name, email;
public:
    Participant(string n = "", string e = "") : name(n), email(e) {}
};

class Team {
protected:
    string teamName, projectTitle;
public:
    Team(string t = "", string p = "") : teamName(t), projectTitle(p) {}
};

class ParticipantRecord : public Participant, public Team {
public:
    ParticipantRecord(string n, string e, string t, string p)
        : Participant(n, e), Team(t, p) {}

    ParticipantRecord(const ParticipantRecord &other)
        : Participant(other.name, other.email),
          Team(other.teamName, other.projectTitle) {}

    void display() {
        cout << "Participant: " << name << " | Email: " << email << endl;
        cout << "Team: " << teamName << " | Project: " << projectTitle << endl;
    }
};

int main() {

    ParticipantRecord p1("Alice", "alice@example.com", "Team Alpha", "AI Project");

    ParticipantRecord p2(p1);


    cout << "Original Record:" << endl;
    p1.display();

    cout << "Copied Record:" << endl;
    p2.display();

    return 0;
}
