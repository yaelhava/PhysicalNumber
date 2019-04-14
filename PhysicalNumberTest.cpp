/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber e(100, Unit::KG);
    PhysicalNumber f(200 , Unit::G);
    PhysicalNumber g(1, Unit::TON);
    PhysicalNumber h(10, Unit::CM);
    PhysicalNumber i(7, Unit::SEC);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    
    .CHECK_OUTPUT(e, "100[kg]")
    .CHECK_OUTPUT(f, "200[g]")
    .CHECK_OUTPUT(g, "1[ton]")
    .CHECK_OUTPUT(h, "10[cm]")
    .CHECK_OUTPUT(i, "7[sec]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .CHECK_OUTPUT(e+f, "100.2[kg]")
    .CHECK_OUTPUT(f+e, "100200[g]")
    .CHECK_OUTPUT(i+c, "7207[sec]")
    .CHECK_OUTPUT(g-e, "0.9[ton]")
    .CHECK_OUTPUT((g+=g), "2[ton]")
    .CHECK_OUTPUT(g, "2[ton]")
    .CHECK_OUTPUT(-g, "-2[ton]")
    .CHECK_OUTPUT(+i, "7[sec]")
    .CHECK_OUTPUT((++i), "8[sec]")
    .CHECK_OUTPUT(d-d, "0[min]")
    .CHECK_OUTPUT((f-=f), "0[g]")
    .CHECK_OUTPUT((f+=e), "100000[g]")
    .CHECK_EQUAL((f==e), true)
    .CHECK_OUTPUT(g+f, "2.1[ton]")
    .CHECK_OUTPUT(a+h, "2.3001[km]")
    .CHECK_OUTPUT(h+b, "30010[cm]")
    .CHECK_OUTPUT(b+h, "300.1[m]")
    .CHECK_OUTPUT((h+=h), "20[cm]")
    .CHECK_OUTPUT((h+=h), "40[cm]")
    .CHECK_OUTPUT(h-h, "0[cm]")
    .CHECK_OUTPUT(b+b, "600[m]")
    .CHECK_OUTPUT((++a), "3.3[km]")
    .CHECK_OUTPUT((--c), "1[hour]")
    .CHECK_OUTPUT(c+d, "1.5[hour]")




    .CHECK_THROWS(a+e)
    .CHECK_THROWS(c+=h)
    .CHECK_THROWS(i-f)
    .CHECK_THROWS(d<h)
    .CHECK_THROWS(g<=i)
    .CHECK_THROWS(b==f)
    .CHECK_THROWS(g+=h)
    .CHECK_THROWS(e+c)
    .CHECK_THROWS(f+c)
    .CHECK_THROWS(a-g)
    .CHECK_THROWS(c<b)
    .CHECK_THROWS(b+=g)
    .CHECK_THROWS(i-a)
    .CHECK_THROWS(f-=i)
    .CHECK_THROWS(a!=e)
    .CHECK_THROWS(d<=g)
    .CHECK_THROWS(b>g)
    .CHECK_THROWS(h>(e+f))
    .CHECK_THROWS(i==f)


    .CHECK_EQUAL((f!=g), true)
    .CHECK_EQUAL((e!=f), false)
    .CHECK_EQUAL((c>i), true)
    .CHECK_EQUAL((h>a), false)
    .CHECK_EQUAL((d==c), false)
    .CHECK_EQUAL((b>=a), false)
    .CHECK_EQUAL((a>=b), true)
    .CHECK_EQUAL((b<=a), true)
    .CHECK_EQUAL((e>=f), true)
    .CHECK_EQUAL((g>=f), true)
    .CHECK_EQUAL((i!=c), true)
    .CHECK_EQUAL((i==c), false)
    .CHECK_EQUAL((d>=i), true)
    .CHECK_EQUAL((a>=h), true)
    .CHECK_EQUAL((f<=e), true)
    .CHECK_EQUAL((f>=e), true)
    .CHECK_EQUAL((g!=e), true)
    .CHECK_EQUAL((e>g), false)
    .CHECK_EQUAL((i>d), false)

    .CHECK_OUTPUT((c+d+d), "2[hour]")
    .CHECK_OUTPUT((e+f-f), "100[kg]")
    .CHECK_OUTPUT((f+e-f), "100000[g]")
    .CHECK_OUTPUT((a+b-b), "3.3[km]")
    .CHECK_OUTPUT((g+e+e), "2.2[ton]")
    .CHECK_OUTPUT((c++), "1[hour]")  ///?????!?!?!?!
    .CHECK_OUTPUT((g--), "2[ton]")  //?!?!?!?!?!?!?


    .CHECK_OK(istringstream("26[sec]") >> i)
    .CHECK_OK(istringstream("12[ton]") >> g)
    .CHECK_OUTPUT(g, "12[ton]")
    .CHECK_OUTPUT(i, "26[ton]")


    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
