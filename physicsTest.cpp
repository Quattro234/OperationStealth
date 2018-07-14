#include <iostream>
#include <string>

class object {
private:
  double mass;
  double gravity;
};

class freeMovingBody {
private:
  std::string name;

  double displacement[2];
  double velocity[2] = {0, 0};
  double acceleration[2] = {0, 0};
  double force[2] = {0, 0};

  double mass;
  double gravity;
public:
  void displayPosition() {
    std::cout << "The "<< name << " body is ("<< displacement[0] <<" , " << displacement[1] << ") from the origin with force ("<< force[0] <<" , " << force[1] << ")" << std::endl;
  }

  void setName(std::string str) {name = str;}
  void setGravity(double foo) {gravity = foo;}

  void velocityToDisplacement() {
    for(int i=0; i<2; i++){
      displacement[i] += velocity[i];
    }
  };
  void accelerationToVelocity() {
    for(int i=0; i<2; i++){
      velocity[i] += acceleration[i];
    }
  };
  void forceToAcceleration() {
    for(int i=0; i<2; i++){
      acceleration[i] = (force[i]/mass);
    }
  };

  void applyWeight() {force[1] += -(mass * gravity);}
  void resetForces() {for(int i=0; i<1; i++) {force[i]=0;}}
  freeMovingBody(std::string initialName, double x_disp, double y_disp) {
    initialName = name;
    displacement[0] = x_disp;
    displacement[1] = y_disp;
    mass = mass;
  };
  ~freeMovingBody(){};
};

int main() {

  freeMovingBody ball("baller", 10.0, 10.0);
  ball.setName("baller");
  ball.displayPosition();

  ball.setGravity(9.81);

  for(int i=0; i<10; i++) {

   /* other actions the PC or NPC do go here before physcis calculation */

    ball.applyWeight();
    ball.forceToAcceleration();
    ball.accelerationToVelocity();
    ball.velocityToDisplacement();
    ball.displayPosition();
  //  ball.resetForces();
  }

 return 0;
}
