#include<iostream>

class person {
  public:
    void identitty() {
      std::cout << "Am a person\n";
    }

    void special() {
      std::cout << "Special Base prop\n";
    }
  private:

};

class student : public person {
  public:
    void identitty() {
      std::cout << "Am a Student\n";
    }

  private:

};

int main()
{

  person* p = new person();
  p->identitty();
  delete p;

  p = new student();
  p->identitty();
  delete p;

  student* s = new student();
  s->identitty();
  s->special();
  delete s;

  /* Error
  s = new person();
  s->identitty();
  delete s;
  */
  return 0;
}
