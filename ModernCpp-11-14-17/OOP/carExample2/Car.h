//
// Created by cheetos on 9/11/18.
//

#ifndef CAREXAMPLE2_CAR_H
#define CAREXAMPLE2_CAR_H


class Car {
    private:
        float fuel;
        float speed;
        int passagers;
        static int count;

    public:
        Car();
        Car(float amount);
        Car(float amout, int passagers);

        ~Car();

        void FillFuel(float amount);
        void Accelerate();
        void Brake();        void Dashboard();
};


#endif //CAREXAMPLE2_CAR_H
