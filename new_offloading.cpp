#include <iostream>
#include <cstdio>
#include <time.h> 
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip> // setprecision
#include <vector>
#include <random>
#include <iterator> 
#include <map> 

using namespace std;

    default_random_engine eng{static_cast<long unsigned int>(time(0))};
    uniform_real_distribution<double> distribution(0.0,1.0);

class RandomNumber{

    private:
    double rate;
    double GenExpo(double u)
    {
        double randomNum = distribution(eng);
        //cout <<"rr: " <<randomNum << endl;
        return (-(double)1/u)*log(randomNum);
    }

    int chooseNumber(double p[],int size)
    {
        double randomNum = distribution(eng);
        double r = randomNum;
        int nums = 0;
        double pi = 0;
        //cout << "r=" << r <<endl;
        for(int i=0;i<size;i++)
        {
            //cout << "P["<<i<<"]="<<p[i] <<endl;
            pi +=p[i];
            //cout << "r=" <<r << ", pi="<<pi <<endl;
            if(r<=pi)
            {
                nums = i;
                break;
            }
        }
        return nums;
    }

    public:
    double mean;
    double ranNumber;
    
    RandomNumber()
    {
        rate = -1;
    }

    RandomNumber(double mean)
    {
        rate = 1/mean;
    }
    double getMean()
    {
        return mean;
    }
    double getRate()
    {
        return rate;
    }
    double getRandomExpo()
    {
        return GenExpo(rate);
    }
    double getNumbers(double p[],int size)
    {
        return chooseNumber(p,size);
    }

};

class WiFiRate{
    private:
    double EVo, EVd,E4G, Pmiss;

    public:
    double r0, rc, r1, r2, r3, co;

    WiFiRate(): WiFiRate(0,0,0,0,0){}

    WiFiRate(double r0, double rc): WiFiRate(r0,rc,r1,r2,0){}

    WiFiRate(double r0, double rc, double r1,double r2): WiFiRate(r0,rc,r1,r2,0){}

    WiFiRate(double r0, double rc, double r1,double r2,double r3){
        //cout << "Hello comr here" <<endl;
        this->r0 = r0;
        this->rc = rc;
        this->co = co;
        this->r1 = r1;
        this->r2 = r2;
        this->r3 = r3;
        //this->r1 = 
    }
    
    void setR0(double r0){
        this->r0 = r0;
    }
    void setRC(double rc){
        this->rc = rc;
    }
    void setR1(double r1){

        this->r1 = r1;
       // this->r1 = ((et1+et2)/(et1+(this->co*et2)))*(getRateWiFi());  
    }

    void setR2(double r2){
        this->r2 = r2;
        //this->r2 = getRateWiFi1()*(this->co);
    }
    void setR3(double r3){
        this->r3 = r3;
        //this->r2 = getRateWiFi1()*(this->co);
    }

    double getRateLTE()
    {
        return r0;
    }
    double getRateWiFi()
    {
        return rc;
    }
    double getRateWiFi1()
    {
        return this->r1;
    }
    double getRateWiFi2()
    {
        return  this->r2;
    }
    double getRateWiFi3()
    {
        return  this->r3;
    }
    double getPmiss(){
        return Pmiss;
    }
    double getAverageVolume(){
        return EVd;
    }
    double getAverageVolumeWiFi(){
        return EVo;
    }
     double getAverageVolume4G(){
        return E4G;
    }

    void downloadingFile(int N_sim,double file_size,double ets,double et0,double etC,int model){
        downloadingFile(N_sim,file_size,ets,et0,etC,-1,-1,-1,1);
    }
    void downloadingFile(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,int model){
        downloadingFile(N_sim,file_size,ets,et0,etC,et1,et2,-1,2);
    }
    void downloadingFile(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,double et3,int model)
    {
        RandomNumber ins;
        double plist[2] = {et0/(et0+etC),etC/(et0+etC)};
        int wifistatus = ins.getNumbers(plist,2) ;
        RandomNumber gts(ets),gt0(et0),gtC(etC),gt1(et1),gt2(et2), gt3(et3);
        double tsi = 0;
        int use_statatus = 0;
        double tnext = -1;
        double tnext2 = -1;
        int useTnext = 0;
        int useTnext2 = 0;
        int chooseWiFirate = 1;
        int countMiss = 0;
        double totaldownload = 0;
        double totaldownloadbyWiFi = 0;
        double totaldownloadby4G = 0;
        double ats = 0;
        double sum_ts = 0;
        int debug = 0;

        switch(model){
            case 1:
                cout << "===== Download by Model 1 =====" <<endl;
                
                for(int i=0;i<N_sim;i++)
                {
                    double bit_file_size = file_size*8;
                    tsi = gts.getRandomExpo();
                    sum_ts+=tsi;
                    //cout << "ts======= : " <<tsi <<endl;
                    do
                    {

                        if(!wifistatus)
                        {
                            double download = 0;
                            double t0 = 0;
                            if(useTnext){
                                t0 = tnext;
                            }
                            else{
                                t0 = gt0.getRandomExpo();
                            }
                            //cout << "t0 : " << t0 <<endl;
                            tsi -= t0;
                            if(tsi<0)
                            {
                                tnext = (-1)*tsi;
                                t0 += tsi;
                                useTnext = 1;
                                //cout << "tnext 0 : " << tnext << endl;
                                //cout << "new t0 :" << t0<<endl;
                            }
                            else
                            {
                                wifistatus = 1;
                                useTnext =0;
                            }
                            //cout << "Speed 0: " << getRateLTE() << endl;
                            download =  (t0*getRateLTE());
                            bit_file_size -= download;


                            if(bit_file_size<0)
                            {
                                download += bit_file_size;
                            }
                            totaldownloadby4G += download;
                            totaldownload+=download;
                            /* cout << "download 4G:" << download << endl;
                            cout << "total 4G:" << totaldownloadby4G << endl; */

                           
                        }
                        else
                        {
                            double download = 0;
                            double download_WiFi = 0;
                            double download_4G = 0;
                            double tC = 0;
                            if(useTnext)
                            {
                                tC = tnext;
                            }
                            else
                            {
                                tC = gtC.getRandomExpo();
                            }
                            //cout << "tc : " <<tC <<endl;
                            tsi -= tC;
                            if(tsi<0)
                            {
                                tnext = (-1)*tsi;
                                tC += tsi;
                                useTnext = 1;
                                //cout << "tnext C : " << tnext << endl;
                                //cout << "new tC :" << tC<<endl;
                            }
                            else
                            {
                                wifistatus = 0;
                                useTnext =0;
                            }
                            download =  (tC*(getRateLTE()+ getRateWiFi()));
                            download_WiFi = tC*getRateWiFi();
                            download_4G = tC*getRateLTE();
                            bit_file_size -= download;
                            if(bit_file_size<0)
                            {
                                /*double wifi_part =  bit_file_size + download;
                                if((wifi_part-download_WiFi)<0)
                                {
                                    download_WiFi = wifi_part;
                                }
                                download += bit_file_size;*/
                                double download_part =  bit_file_size + download;
                                download = download_part;
                                download_WiFi =  download_part*(getRateWiFi()/(getRateWiFi()+getRateLTE()));
                                download_4G =  download_part*(getRateLTE()/(getRateWiFi()+getRateLTE()));
                                
                            }
                            totaldownload+=download;
                            totaldownloadbyWiFi+= download_WiFi;
                            totaldownloadby4G+= download_4G; // because 4G = WIFI in thsi case
                            /* cout << "download :" << download << endl;
                            cout << "download_4G :" << download_4G << endl;
                            cout << "download_WiFi :" << download_WiFi << endl;
                            cout << " totaldownloadbyWiFi :" << totaldownloadbyWiFi <<endl;
                            cout << " totaldownloadby4G :" << totaldownloadby4G <<endl; */
                        }

                    }while(tsi>0 && bit_file_size>0);
                    //cout << "remain bit_file_size :" << bit_file_size << endl;
                    if(bit_file_size>0)
                    {
                        //cout << "countMiss :" << countMiss << endl;
                        countMiss++;
                    }
                }
                //cout << "Cout_miss : " <<countMiss <<endl;
                this-> EVo = totaldownloadbyWiFi/(8*((double)N_sim));
                this-> EVd = totaldownload/(8*((double)N_sim));
                this->Pmiss = (double)countMiss/(double)N_sim;
                this->E4G = totaldownloadby4G/(8*((double)N_sim));
                
                ats= sum_ts/(double)N_sim;
                //cout << "mean of ts :" << ats <<endl;
                break;
            case 2:
            cout << "===== Download by Model 2 =====" <<endl;

                for(int i=0;i<N_sim;i++)
                {
                    double bit_file_size = file_size*8;
                    tsi = gts.getRandomExpo();
                    sum_ts +=tsi;
                    //cout << "ts======= : " <<tsi <<endl;
                    do
                    {
                        if(!wifistatus)
                        {
                            double download = 0;
                            double t0 = 0;

                            if(useTnext)
                            {
                                t0 = tnext;
                            } 
                            else
                            {
                                t0 = gt0.getRandomExpo();
                            }
                            //cout << "t0 : " << t0 <<endl;
                            tsi -= t0;
                
                            if(tsi<0){
                                tnext = (-1)*tsi;
                                t0 += tsi;
                                useTnext = 1;
                                //cout << "tnext 0 : " << tnext << endl;
                                //cout << "new t0 :" << t0<<endl;
                            }
                            else{
                                wifistatus = 1;
                                useTnext =0;
                            }

                            download = getRateLTE()*t0;
                            bit_file_size -= (download);
                            if(bit_file_size<0)
                            {
                                download += bit_file_size;
                            }
                            totaldownload+=download;
                            totaldownloadby4G += download;
                            /* cout << "download 4G:" << download << endl;
                            cout << "total 4G:" << totaldownloadby4G << endl; */
                        }
                        else
                        {
                            double tc =0;
                            double t1 = 0;
                            double t2 = 0;
                            double download_WiFi = 0;
                            double download = 0;
                            double download_4G = 0;
                            if(useTnext)
                            {
                                tc = tnext;
                            } 
                            else
                            {
                                tc = gtC.getRandomExpo();
                                double tt1 = gt1.getRandomExpo();
                                double tt2 = gt2.getRandomExpo();
                                if(tt1<tt2)
                                {
                                    chooseWiFirate=1;
                                }
                                else{
                                    chooseWiFirate=2;
                                }
                            }

                            //cout << "tc : " << tc <<endl;
                            tsi -= tc;
                            if(tsi<0)
                            {
                                tnext = (-1)*tsi;
                                useTnext = 1;
                                tc += tsi;
                               // cout << "tnext c : " << tnext << endl;
                               // cout << "tc for loop : " << tc << endl;
                            }
                            else
                            {
                                wifistatus = 0;
                                useTnext =0;
                            }

                            do
                            {
                                if(chooseWiFirate==1)
                                {
                                    double download = 0;
                                    double download_wifi = 0;
                                    
                                    if(useTnext2)
                                    {
                                        t1 = tnext2;
                                    }
                                    else{
                                        t1 = gt1.getRandomExpo(); 
                                    }
                                    tc-=t1;
                                    //cout << "t1 : " << t1 <<endl;
                                    if(tc<0)
                                    {
                                        if(useTnext)
                                        {
                                            tnext2 = -1*tc;
                                            useTnext2 = 1;
                                           //cout << "tnext2 1 : " << tnext2 <<endl;
                                        }
                                        else
                                        {
                                            useTnext2 = 0;
                                        }
                                        t1+=tc;
                                    //cout << "new t1 : " << t1 <<endl;
                                    }
                                    else
                                    {
                                        chooseWiFirate=2;
                                        useTnext2 = 0; 
                                    }

                                    download =  (t1*(getRateLTE()+ getRateWiFi1()));
                                    download_WiFi = t1*getRateWiFi1();
                                    download_4G = t1*getRateLTE();
                                    //cout << "r1 in loop : " << getRateWiFi1()<<endl;
                                    bit_file_size -= download;
                                    if(bit_file_size<0)
                                    {
                                        /*
                                        double wifi_part =  bit_file_size + download;
                                        if((wifi_part-download_WiFi)<0)
                                        {
                                            download_WiFi = wifi_part;
                                        }
                                        download += bit_file_size;*/
                                        double download_part =  bit_file_size + download;
                                        download = download_part;
                                        download_WiFi =  download_part*(getRateWiFi1()/(getRateWiFi1()+getRateLTE()));
                                        download_4G =  download_part*(getRateLTE()/(getRateWiFi1()+getRateLTE()));
 
                                    }
                                    totaldownload+=download;
                                    totaldownloadbyWiFi+= download_WiFi;
                                    totaldownloadby4G+= download_4G; // because 4G = WIFI in thsi case
                                    /* cout << "download :" << download << endl;
                                    cout << "download_4G :" << download_4G << endl;
                                    cout << "download_WiFi :" << download_WiFi << endl;
                                    cout << " totaldownloadbyWiFi :" << totaldownloadbyWiFi <<endl;
                                    cout << " totaldownloadby4G :" << totaldownloadby4G <<endl; */
                                    

                                }
                                else if(chooseWiFirate==2)
                                {
                                    double download = 0;
                                    double download_wifi = 0;
                                    if(useTnext2)
                                    {
                                        t2 = tnext2;
                                    }
                                    else{
                                        t2 = gt2.getRandomExpo(); 
                                    }
                                    tc-=t2;
                                    //cout << "t2 : " << t2 <<endl;
                                    if(tc<0)
                                    {
                                        if(useTnext)
                                        {
                                            tnext2 = -1*tc;
                                            useTnext2 = 1;
                                           // cout << "tnext2 2 : " << tnext2 <<endl;
                                        }
                                        else
                                        {
                                            useTnext2 = 0;
                                        }
                                        t2+=tc;
                                        //cout << "new t2 : " << t2 <<endl;
                                    }
                                    else
                                    {
                                        chooseWiFirate=1;
                                        useTnext2 = 0; 
                                    }

                                    download =  (t2*(getRateLTE()+ getRateWiFi2()));
                                    download_WiFi = t2*getRateWiFi2();
                                    download_4G = t2*getRateLTE();
                                   // cout << "r2 in loop : " << getRateWiFi2()<<endl;
                                    bit_file_size -= download;
                                    if(bit_file_size<0)
                                    {
                                        /*double wifi_part =  bit_file_size + download;
                                        if((wifi_part-download_WiFi)<0)
                                        {
                                            download_WiFi = wifi_part;
                                        }
                                        download += bit_file_size;*/
                                        double download_part =  bit_file_size + download;
                                        download = download_part;
                                        download_WiFi =  download_part*(getRateWiFi2()/(getRateWiFi2()+getRateLTE()));
                                        download_4G =  download_part*(getRateLTE()/(getRateWiFi2()+getRateLTE()));
                                        
                                    }
                                    totaldownload+=download;
                                    totaldownloadbyWiFi+= download_WiFi;
                                    totaldownloadby4G+= download_4G;
                                    
                                    /* cout << "download :" << download << endl;
                                    cout << "download_4G :" << download_4G << endl;
                                    cout << "download_WiFi :" << download_WiFi << endl;
                                    cout << " totaldownloadbyWiFi :" << totaldownloadbyWiFi <<endl;
                                    cout << " totaldownloadby4G :" << totaldownloadby4G <<endl; */
                                }
                                
                            //cout <<"bit_file_size:"<< bit_file_size<<endl; 
                            }while(tc>0 && bit_file_size>0);
                        }

                    }while(tsi>0 && bit_file_size>0);
                    //cout <<"remain_bit_file_size:"<< bit_file_size<<endl; 
                    if(bit_file_size>0)
                    {
                        countMiss++;
                    }

                }
                //cout << "Cout_miss : " <<countMiss <<endl;
                this->EVo = totaldownloadbyWiFi/(8*((double)N_sim));
                this->EVd = totaldownload/(8*((double)N_sim));
                this->Pmiss = (double)countMiss/(double)N_sim;
                this->E4G = totaldownloadby4G/(8*((double)N_sim));
             
                ats= sum_ts/(double)N_sim;
                //cout << "mean of ts :" << ats <<endl;

                break;
            case 3:
            cout << "===== Download by Model 3 =====" <<endl;
            
            for(int i=0;i<N_sim;i++)
            {
                double bit_file_size = file_size*8;
                tsi = gts.getRandomExpo();
                sum_ts +=tsi;
                if(debug)
                {
                    cout <<"================" << "Ts = " << tsi <<"================" <<endl;
                    cout << "bit_file_size = " << bit_file_size  <<endl;
                }
                do
                {
                    if(!wifistatus)
                    {
                        double download = 0;
                        double t0 = 0;
                        double tt0 = 0;

                        if(useTnext)
                        {
                            t0 = tnext;
                        } 
                        else
                        {
                            t0 = gt0.getRandomExpo();
                        }
                        //cout << "t0 : " << t0 <<endl;
                        tsi -= t0;
                        tt0 = t0;
            
                        if(tsi<0){
                            tnext = (-1)*tsi;
                            tt0 = t0+tsi; 
                            t0 += tsi;
                            useTnext = 1;
                            
                            //cout << "tnext 0 : " << tnext << endl;
                            //cout << "new t0 :" << t0<<endl;
                        }
                        else{
                            wifistatus = 1;
                            useTnext =0;
                        }

                        download = getRateLTE()*t0;
                        bit_file_size -= (download);
                        if(bit_file_size<0)
                        {
                            download += bit_file_size;
                        }
                        totaldownload+=download;
                        totaldownloadby4G += download;

                        if(debug)
                        {
                            cout << " t0:" << tt0 ;
                            cout << " remaining bit size : " << bit_file_size ;
                        }

                    }
                    else
                    {
                        double tc =0;
                        double ttc =0;
                        double t1 = 0;
                        double t2 = 0;
                        double t3 = 0;
                        double download_WiFi = 0;
                        double download = 0;
                        double download_4G = 0;

                        if(useTnext)
                        {
                            tc = tnext;
                        } 
                        else
                        {
                            tc = gtC.getRandomExpo();
                            double qlist[3] = {et1/(et1+et2+et3),et2/(et1+et2+et3),et3/(et1+et2+et3)};
                            chooseWiFirate = ins.getNumbers(qlist,3)+1;
                        }
                        ttc = tc;
                        tsi -= tc;
                        if(tsi<0)
                        {
                            tnext = (-1)*tsi;
                            useTnext = 1;
                            tc += tsi;
                            ttc = tc;
                            // cout << "tnext c : " << tnext << endl;
                            // cout << "tc for loop : " << tc << endl;
                        }
                        else
                        {
                            wifistatus = 0;
                            useTnext =0;
                        }

                        do
                        {
                            if(chooseWiFirate==1)
                            {
                                double download = 0;
                                double download_wifi = 0;
                                double tt1 = 0;
                                
                                if(useTnext2)
                                {
                                    t1 = tnext2;
                                }
                                else{
                                    t1 = gt1.getRandomExpo(); 
                                }
                                tt1 = t1;
                                tc-=t1;
                                //cout << "t1 : " << t1 <<endl;
                                if(tc<0)
                                {
                                    if(useTnext)
                                    {
                                        tnext2 = -1*tc;
                                        useTnext2 = 1;
                                        //cout << "tnext2 1 : " << tnext2 <<endl;
                                    }
                                    else
                                    {
                                        useTnext2 = 0;
                                    }

                                    t1+=tc;
                                    tt1 = t1;
                                //cout << "new t1 : " << t1 <<endl;
                                }
                                else
                                {
                                    double clist[2]={et2/(et2+et3),et3/(et2+et3)};
                                    chooseWiFirate=(ins.getNumbers(clist,2))+2;
                                    useTnext2 = 0; 
                                }

                                download =  (t1*(getRateLTE()+ getRateWiFi1()));
                                download_WiFi = t1*getRateWiFi1();
                                download_4G = t1*getRateLTE();
                                //cout << "r1 in loop : " << getRateWiFi1()<<endl;
                                bit_file_size -= download;

                                if(bit_file_size<0)
                                {
                                    /*
                                    double wifi_part =  bit_file_size + download;
                                    if((wifi_part-download_WiFi)<0)
                                    {
                                        download_WiFi = wifi_part;
                                    }
                                    download += bit_file_size;*/
                                    double download_part =  bit_file_size + download;
                                    download = download_part;
                                    download_WiFi =  download_part*(getRateWiFi1()/(getRateWiFi1()+getRateLTE()));
                                    download_4G =  download_part*(getRateLTE()/(getRateWiFi1()+getRateLTE()));

                                }
                                totaldownload+=download;
                                totaldownloadbyWiFi+= download_WiFi;
                                totaldownloadby4G+= download_4G; // because 4G = WIFI in thsi case
                                /* cout << "download :" << download << endl;
                                cout << "download_4G :" << download_4G << endl;
                                cout << "download_WiFi :" << download_WiFi << endl;
                                cout << " totaldownloadbyWiFi :" << totaldownloadbyWiFi <<endl;
                                cout << " totaldownloadby4G :" << totaldownloadby4G <<endl; */

                                if(debug)
                                {
                                    cout << " t1:" << tt1 ;
                                    cout << " remaining bit size : " << bit_file_size ;
                                }
                                

                            }
                            else if(chooseWiFirate==2)
                            {
                                double download = 0;
                                double download_wifi = 0;
                                double tt2 = 0;
                                if(useTnext2)
                                {
                                    t2 = tnext2;
                                }
                                else{
                                    t2 = gt2.getRandomExpo(); 
                                }
                                tt2 = t2;
                                tc-=t2;
                                //cout << "t2 : " << t2 <<endl;
                                if(tc<0)
                                {
                                    if(useTnext)
                                    {
                                        tnext2 = -1*tc;
                                        useTnext2 = 1;
                                        // cout << "tnext2 2 : " << tnext2 <<endl;
                                    }
                                    else
                                    {
                                        useTnext2 = 0;
                                    }
                                    t2+=tc;
                                    tt2 = t2;
                                    //cout << "new t2 : " << t2 <<endl;
                                }
                                else
                                {
                                    double clist[2]={et1/(et1+et3),et3/(et1+et3)};
                                    chooseWiFirate=(ins.getNumbers(clist,2)==1)?3:1;
                                    useTnext2 = 0; 

                                    //chooseWiFirate=1;
                                    //useTnext2 = 0; 
                                }

                                download =  (t2*(getRateLTE()+ getRateWiFi2()));
                                download_WiFi = t2*getRateWiFi2();
                                download_4G = t2*getRateLTE();
                                // cout << "r2 in loop : " << getRateWiFi2()<<endl;
                                bit_file_size -= download;
                                if(bit_file_size<0)
                                {
                                    /*double wifi_part =  bit_file_size + download;
                                    if((wifi_part-download_WiFi)<0)
                                    {
                                        download_WiFi = wifi_part;
                                    }
                                    download += bit_file_size;*/
                                    double download_part =  bit_file_size + download;
                                    download = download_part;
                                    download_WiFi =  download_part*(getRateWiFi2()/(getRateWiFi2()+getRateLTE()));
                                    download_4G =  download_part*(getRateLTE()/(getRateWiFi2()+getRateLTE()));
                                    
                                }
                                totaldownload+=download;
                                totaldownloadbyWiFi+= download_WiFi;
                                totaldownloadby4G+= download_4G;

                                if(debug)
                                {
                                    cout << " t2:" << tt2 ;
                                    cout << " remaining bit size : " << bit_file_size ;
                                }
                                
                                /* cout << "download :" << download << endl;
                                cout << "download_4G :" << download_4G << endl;
                                cout << "download_WiFi :" << download_WiFi << endl;
                                cout << " totaldownloadbyWiFi :" << totaldownloadbyWiFi <<endl;
                                cout << " totaldownloadby4G :" << totaldownloadby4G <<endl; */
                            }
                            else if(chooseWiFirate==3)
                            {
                                double tt3 = 0;
                                double download = 0;
                                double download_wifi = 0;
                                if(useTnext2)
                                {
                                    t3 = tnext2;
                                }
                                else{
                                    t3 = gt3.getRandomExpo(); 
                                }
                                tc-=t3;
                                tt3 = t3;
                                //cout << "t2 : " << t2 <<endl;
                                if(tc<0)
                                {
                                    if(useTnext)
                                    {
                                        tnext2 = -1*tc;
                                        useTnext2 = 1;
                                        // cout << "tnext2 2 : " << tnext2 <<endl;
                                    }
                                    else
                                    {
                                        useTnext2 = 0;
                                    }
                                    t3+=tc;
                                    tt3 = t3;
                                    //cout << "new t2 : " << t2 <<endl;
                                }
                                else
                                {
                                    double clist[2]={et1/(et1+et2),et2/(et1+et2)};
                                    chooseWiFirate=ins.getNumbers(clist,2)+1;
                                    useTnext2 = 0; 

                                   
                                }

                                download =  (t3*(getRateLTE()+ getRateWiFi3()));
                                download_WiFi = t3*getRateWiFi3();
                                download_4G = t3*getRateLTE();
                                // cout << "r2 in loop : " << getRateWiFi2()<<endl;
                                bit_file_size -= download;
                                if(bit_file_size<0)
                                {
                                    /*double wifi_part =  bit_file_size + download;
                                    if((wifi_part-download_WiFi)<0)
                                    {
                                        download_WiFi = wifi_part;
                                    }
                                    download += bit_file_size;*/
                                    double download_part =  bit_file_size + download;
                                    download = download_part;
                                    download_WiFi =  download_part*(getRateWiFi3()/(getRateWiFi3()+getRateLTE()));
                                    download_4G =  download_part*(getRateLTE()/(getRateWiFi3()+getRateLTE()));
                                    
                                }
                                totaldownload+=download;
                                totaldownloadbyWiFi+= download_WiFi;
                                totaldownloadby4G+= download_4G;
                                if(debug)
                                {
                                    cout << " t3:" << tt3 ;
                                    cout << " remaining bit size : " << bit_file_size ;
                                }
                            }

                            

                        }while(tc>0  && bit_file_size>0 );
                    }
               

                }while(tsi>0  && bit_file_size>0);

                if(debug)
                {
                    cout << endl ;
                }

                if(bit_file_size>0)
                {
                    countMiss++;
                }

            }
            this->EVo = totaldownloadbyWiFi/(8*((double)N_sim));
            this->EVd = totaldownload/(8*((double)N_sim));
            this->Pmiss = (double)countMiss/(double)N_sim;
            this->E4G = totaldownloadby4G/(8*((double)N_sim));
            
            ats= sum_ts/(double)N_sim;
                //cout << "mean of ts :" << ats <<endl;

                break;
            default:
                break;
        }

    }

    void printReport(int N_sim,double file_size,double ets,double et0, double etC,int model)
    {
        printReport(N_sim, file_size, ets, et0,  etC,-1,-1,-1,model);
    }

    void printReport(int N_sim,double file_size,double ets,double et0, double etC, double et1,double et2,int model)
    {
        printReport(N_sim, file_size, ets, et0,  etC,et1, et2,-1,model);
    }

    void printReport(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,double et3,int model)
    {
        cout << "============= Report =============" <<endl;
        cout << "Parameter Settings :" <<endl;
        cout << "Nsim :" << N_sim <<endl;
        cout << "E[Ts] :" << ets <<endl;
        cout << "E[T0] :" << et0 <<endl;
        cout << "E[Tc] :" << etC <<endl;
        if(et1!=-1)
        {
            cout << "E[t1] :" << et1 <<endl;
        }
        if(et2!=-1)
        {
            cout << "E[t2] :" << et2 <<endl;
        }

        if(et3!=-1)
        {
            cout << "E[t3] :" << et3 <<endl;
        }
        cout << "CELLULAR_BANDWIDTH :" << getRateLTE() << " Mbps " <<endl;
        cout << "WIFI_BANDWIDTH :" << getRateWiFi() << " Mbps " << endl;
        if(et1!=-1)
        {
            cout << "WIFI_BANDWIDTH r1 :" << getRateWiFi1() << " Mbps " << endl;
        }

        if(et2!=-1)
        {
            cout << "WIFI_BANDWIDTH r2 :" << getRateWiFi2() << " Mbps " << endl;
        }

        if(et3!=-1)
        {
            cout << "WIFI_BANDWIDTH r3 :" << getRateWiFi3() << " Mbps " << endl;
        }
    
        
        cout << "FILE_SIZE :" << file_size << " MB" <<endl;
        cout << "============= Result =============" <<endl;
        string topic =  (model==1)?" Constant Bandwidth Scheme ":"Multiple Bandwidth Scheme";
        cout <<setw(10)  <<left << "# " <<setw(15)<< topic <<endl;
        cout << setw(10) <<left << "P_Miss" << setw(15)<< right  << getPmiss() <<endl;
        cout << setw(10) <<left << "E[Vo]" << setw(15)<< right  << getAverageVolumeWiFi()<<endl;
        cout << setw(10) <<left << "E[4G]" << setw(15)<< right  << getAverageVolume4G() <<endl;
        cout << setw(10) <<left << "E[Vd]" << setw(15)<< right  << getAverageVolume() <<endl;
    }
    void exportTofile(int N_sim,double file_size,double ets,double et0, double etC,int model)
    {
        cout << "model 1 !!!!" <<endl;
        exportTofile(N_sim, file_size, ets, et0,  etC,-1, -1,-1,model);
    }
    void exportTofile(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,int model)
    {
        cout << "model 2 !!!!" <<endl;
        exportTofile(N_sim, file_size, ets, et0,  etC,et1, et2,-1,model);
    }

    void exportTofile(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,double et3,int model)
    {
        ofstream outfile;
       // string filename = (model==1)?"result_m1.txt": (model==2)?"result_m2.txt":"result_m3.txt";
        string filename = "re_mOffload.txt";
        //cout << "cccc:"<<filename <<endl;
        outfile.open(filename,ios_base::app);
        string content;

        content += to_string(N_sim)+ "," + to_string(ets) + "," + to_string(et0)+ "," + to_string(etC) + "," ; 
        
        if(et1!=-1)
        {
            content  += to_string(et1) + ",";
        }
        else
        {
            content  +=  ",";
        }

        if(et2!=-1)
        {
             content  += to_string(et2) + ",";
        }
        else
        {
            content += ",";
        }

        if(et3!=-1)
        {
            content  += to_string(et3) + ",";
        }
        else
        {
            content += ",";
        }
        
        content += to_string(getRateLTE()) + ","+ to_string(getRateWiFi()) + "," ;
                
        if(et1!=-1)
        {
            content  += to_string(getRateWiFi1()) + ",";
        }
        else
        {
            content  +=  ",";
        }

        if(et2!=-1)
        {
             content  += to_string(getRateWiFi2()) + ",";
        }
        else
        {
            content += ",";
        }

        if(et3!=-1)
        {
            content  += to_string(getRateWiFi3()) + ",";
        }
        else
        {
            content += ",";
        }
                
        content += to_string(file_size)+ "," + to_string(getPmiss()) + "," +  to_string(getAverageVolumeWiFi()) +  "," +  to_string(getAverageVolume()) ;
        outfile << content <<"\n"; 
        outfile.close();
        cout << "Results  are written in "<< filename <<endl;
    }


};



int main(int argc, char *argv[]) 
{
    /* int Nsim = 10000;
    double ets = 250;
    double et0 = 100;
    double etC = 400;
    double et1 = 100;
    double et2 = 250;
    double et3 = 300;
    double b0 = 5 ;// 4G Mbps
    double b1 = 10;// WIFI Mbps
    double r1 = 1 ;// 4G Mbps
    double r2 = 5;// WIFI Mbps
    double r3 = 10;// WIFI Mbps
    double file_size = 100; // MB
    int model = 3; */

     // WiFiRate w1(b0,b1), w2(b0,b1,r1,r2);
     //WiFiRate w3(b0,b1,r1,r2,r3);

    // simulation
   //cout << model<<endl;

    int Nsim = 0;
    double ets = 0;
    double et0 = 0;
    double etC = 0;
    double et1 = 0;
    double et2 = 0;
    double et3 = 0;
    double b0 = 0;// 4G Mbps
    double b1 = 0;// WIFI Mbps
    double r1 = 0 ;// 4G Mbps
    double r2 = 0;// WIFI Mbps
    double r3 = 0;// WIFI Mbps
    double file_size = 0; // MB
    int model = 0;

    if (argc == 9)
    {
		Nsim = atoi(argv[1]);
        ets = atof(argv[2]);
        et0 = atof(argv[3]);
        etC = atof(argv[4]);
        b0 = atof(argv[5]) ;// 4G Mbps
        b1 = atof(argv[6]) ;// WIFI Mbps
        file_size = atof(argv[7]); // MB
        model = atoi(argv[8]);
	}
    else if(argc == 13)
    {
        Nsim = atoi(argv[1]);
        ets = atof(argv[2]);
        et0 = atof(argv[3]);
        etC = atof(argv[4]);
        et1 = atof(argv[5]);
        et2 = atof(argv[6]); 
        b0 = atof(argv[7]);// 4G Mbps
        b1 = atof(argv[8]);// WIFI Mbps
        r1 = atof(argv[9]) ;// WIFI 1 Mbps
        r2 = atof(argv[10]);// WIFI 2 Mbps       
        file_size = atof(argv[11]); // MB
        model = atoi(argv[12]);
    } 
    else if(argc==15)
    {
        Nsim = atoi(argv[1]);
        ets = atof(argv[2]);
        et0 = atof(argv[3]);
        etC = atof(argv[4]);
        et1 = atof(argv[5]);
        et2 = atof(argv[6]); 
        et3 = atof(argv[7]); 
        b0 = atof(argv[8]);// 4G Mbps
        b1 = atof(argv[9]);// WIFI Mbps
        r1 = atof(argv[10]) ;// WIFI 1 Mbps
        r2 = atof(argv[11]);// WIFI 2 Mbps    
        r3 = atof(argv[12]);// WIFI 3 Mbps      
        file_size = atof(argv[13]); // MB
        model = atoi(argv[14]);
    }
    else
    {
       cerr << "Usage: " << argv[0] << " <SIM_ROUND> "<< "<E[Ts]> " << "<E[T0]> " << "<E[Tc]> " << "<E[t1]> " << "<E[t2]> "  \
             << "<CELLULAR_BANDWIDTH> " << "<WIFI_BANDWIDTH> " <<  " <WiFi_Rate1> " << " <WiFi_Rate2> " << "<FILE_SIZE> " << endl;
		return 1; 
    }




    switch(model){
        case 1:
        {
            WiFiRate wi(b0,b1);
            //cout << "model 1" <<endl;
            wi.downloadingFile(Nsim,file_size,ets,et0,etC,1);
            wi.printReport(Nsim,file_size,ets,et0,etC,1);
            wi.exportTofile(Nsim,file_size,ets,et0,etC,1);
            
            break;
        }
        case 2:
        {
            WiFiRate wi(b0,b1,r1,r2);
            wi.downloadingFile(Nsim,file_size,ets,et0,etC,et1,et2,2);
            wi.printReport(Nsim,file_size,ets,et0,etC,et1,et2,2);
            wi.exportTofile(Nsim,file_size,ets,et0,etC,et1,et2,2);
            //cout << "model 2" <<endl;
            break;
        }
            
        case 3:
        {
            WiFiRate wi(b0,b1,r1,r2,r3);
            wi.downloadingFile(Nsim,file_size,ets,et0,etC,et1,et2,et3,3);
            wi.printReport(Nsim,file_size,ets,et0,etC,et1,et2,et3,3);
            wi.exportTofile(Nsim,file_size,ets,et0,etC,et1,et2,et3,3);
            //cout << "model 3" <<endl;
            break;
        }
            
        default:
        {
            cout << "test !" <<endl;
            break;
        }
            
    }
   // w1.downloadingFile(Nsim,file_size,ets,et0,etC,1);
    //w2.downloadingFile(Nsim,file_size,ets,et0,etC,et1,et2,2);
    //w3.downloadingFile(Nsim,file_size,ets,et0,etC,et1,et2,et3,3);

    return 0;
}