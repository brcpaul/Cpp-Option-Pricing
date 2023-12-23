#include <iostream>
#include <vector>
#include "CallOption.h"
#include "PutOption.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "BlackScholesPricer.h"
#include "CRRPricer.h"
#include "BinaryTree.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "BlackScholesMCPricer.h"

int main()
{
    double S0(100), K(101.0), T(5), r(0.01), sigma(0.1);
    std::vector<Option*> opt_ptrs;
    //opt_ptrs.push_back(new CallOption(T, K));
    //opt_ptrs.push_back(new PutOption(T, K));
    //opt_ptrs.push_back(new DigitalCallOption(T, K));
    //opt_ptrs.push_back(new DigitalPutOption(T, K));
    
    std::vector<double> fixing_dates;
    for (int i = 1; i <= 5; i++) {
        fixing_dates.push_back(0.1 * i);
    }
    opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
    //opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));


    std::cout << "K: " << K << std::endl << std::endl;
    for (int i = 0; i < fixing_dates.size();i++) {
        std::cout << "vect temps : " << fixing_dates[i] << std::endl << std::endl;
    }

    std::vector<double> ci;
    BlackScholesMCPricer* pricer;

    for (auto& opt_ptr : opt_ptrs) {
        pricer = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
        do {
            pricer->generate(10);
            ci = pricer->confidenceInterval();
            if (pricer->getNbPaths() % 1000 == 0) {
                std::cout << (*pricer)() << std::endl;
            }
            break;
        } while (ci[1] - ci[0] > 1e-2);
        std::cout << "nb samples: " << pricer->getNbPaths() << std::endl;
        std::cout << "price: " << (*pricer)() << std::endl << std::endl;
        delete pricer;
        delete opt_ptr;
    }

    system("pause");

}

    /*
    {

        double S0(100), K(101), T(5), r(0.01), sigma(0.1);
        CallOption opt1(T, K);
        PutOption opt2(T, K);


        std::cout << "European options 1" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(5);
            double U = 0.05;//exp(sigma * sqrt(T / N)) - 1.0;
            double D = -0.045;//exp(-sigma * sqrt(T / N)) - 1.0;
            double R = 0.01;//exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    

    {
        std::cout << "Binary Tree" << std::endl << std::endl;
        BinaryTree<bool> t1;
        t1.setDepth(3);
        t1.setNode(1, 1, true);
        t1.display();
        t1.setDepth(5);
        t1.display();
        t1.setDepth(3);
        t1.display();


        BinaryTree<double> t2;
        t2.setDepth(2);
        t2.setNode(2, 1, 3.14);
        t2.display();
        t2.setDepth(4);
        t2.display();
        t2.setDepth(3);
        t2.display();

        BinaryTree<int> t3;
        t3.setDepth(4);
        t3.setNode(3, 0, 8);
        t3.display();
        t3.setDepth(2);
        t3.display();
        t3.setDepth(4);
        t3.display();

        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {

        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        DigitalCallOption opt1(T, K);
        DigitalPutOption opt2(T, K);


        std::cout << "European options 2" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(5);
            double U = 0.05;//exp(sigma * sqrt(T / N)) - 1.0;
            double D = -0.045;//exp(-sigma * sqrt(T / N)) - 1.0;
            double R = 0.01;//exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1(true) << std::endl;
            std::cout << std::endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2(true) << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }
    system("pause");
    
}
*/