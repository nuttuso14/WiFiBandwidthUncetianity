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
    double EVo, EVd, Pmiss;
    double setRateWiFi1(){
        double rate = (et1/(et1+et2))*rc;
        return rate;
    }
    double setRateWiFi2(){
        double rate = (et2/(et1+et2))*rc;
        return rate;
    }

    public:
    double r0, rc, r1, r2, et1, et2;

    WiFiRate(): WiFiRate(0,0,0,0){}

    WiFiRate(double r0, double rc): WiFiRate(r0,rc,0,0){}

    WiFiRate(double r0, double rc, double r1,double r2){
        //cout << "Hello comr here" <<endl;
        this->r0 = r0;
        this->rc = rc;
        this->r1 = r1;
        this->r2 = r2;
    }
    
    void setR0(double r0){
        this->r0 = r0;
    }
    void setRC(double rc){
        this->rc = rc;
    }
    void setR1(double r1){
        this->r1 = r1;
    }
    void setR2(double r2){
        this->r2 = r2;
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
        return setRateWiFi1();
    }
    double getRateWiFi2()
    {
        return setRateWiFi2();
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

    void downloadingFile(int N_sim,double file_size,double ets,double et0,double etC,int model){
        downloadingFile(N_sim,file_size,ets,et0,etC,-1,-1,1);
    }
    void downloadingFile(int N_sim,double file_size,double ets,double et0, double etC,double et1,double et2,int model){

        RandomNumber ins;
        double plist[2] = {et0/(et0+etC),etC/(et0+etC)};
        int wifistatus = ins.getNumbers(plist,2) ;
        RandomNumber gts(ets),gt0(et0),gtC(etC),gt1(et1),gt2(et2);
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

        switch(model){
            case 1:
                cout << "===== Download by Model 1 =====" <<endl;
                for(int i=0;i<N_sim;i++)
                {
                    double bit_file_size = file_size*8;
                    tsi = gts.getRandomExpo();
                    //cout << "ts============"<<endl;
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
                               // cout << "tnext 0 : " << tnext << endl;
                               // cout << "new t0 :" << t0<<endl;
                            }
                            else
                            {
                                wifistatus = 1;
                                useTnext =0;
                            }
                           // cout << "Speed 0: " << getRateLTE() << endl;
                            download =  (t0*getRateLTE());
                            bit_file_size -= download;

                            

                            if(bit_file_size<0)
                            {
                                download += bit_file_size;
                            }
                            totaldownload+=download;
                           
                        }
                        else
                        {
                            double download = 0;
                            double download_WiFi = 0;
                            double tC = 0;
                            if(useTnext)
                            {
                                tC = tnext;
                            }
                            else
                            {
                                tC = gtC.getRandomExpo();
                            }
                            tsi -= tC;
                            if(tsi<0)
                            {
                                tnext = (-1)*tsi;
                                tC += tsi;
                                useTnext = 1;
                            }
                            else
                            {
                                wifistatus = 0;
                                useTnext =0;
                            }
                            download =  (tC*(getRateLTE()+ getRateWiFi()));
                            download_WiFi = tC*getRateWiFi();
                            bit_file_size -= download;
                            if(bit_file_size<0)
                            {
                                double wifi_part =  bit_file_size + download;
                                if((wifi_part-download_WiFi)<0)
                                {
                                    download_WiFi = wifi_part;
                                }
                                download += bit_file_size;
                                
                            }
                            totaldownload+=download;
                            totaldownloadbyWiFi+= download_WiFi;
                        }

                    }while(tsi>0 && bit_file_size>0);
                    //cout << "remain bit_file_size :" << bit_file_size << endl;
                    if(bit_file_size>0)
                    {
                        //cout << "countMiss :" << countMiss << endl;
                        countMiss++;
                    }
                }
                this-> EVo = totaldownloadbyWiFi/(8*((double)N_sim));
                this-> EVd = totaldownload/(8*((double)N_sim));
                this->Pmiss = (double)countMiss/(double)N_sim;

                break;
            case 2:
            cout << "===== Download by Model 2 =====" <<endl;
                for(int i=0;i<N_sim;i++)
                {
                    double bit_file_size = file_size*8;
                    tsi = gts.getRandomExpo();
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
                        }
                        else
                        {
                            double tc =0;
                            double t1 = 0;
                            double t2 = 0;
                            double download_WiFi = 0;
                            double download = 0;
                            if(useTnext)
                            {
                                tc = tnext;
                            } 
                            else
                            {
                                tc = gt0.getRandomExpo();
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
                                //cout << "tnext c : " << tnext << endl;
                                //cout << "tc for loop : " << tc << endl;
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
                                    // cout << "new t1 : " << t1 <<endl;
                                    }
                                    else
                                    {
                                        chooseWiFirate=2;
                                        useTnext2 = 0; 
                                    }

                                    download =  (t1*(getRateLTE()+ getRateWiFi1()));
                                    download_WiFi = t1*getRateWiFi1();
                                    bit_file_size -= download;
                                    if(bit_file_size<0)
                                    {
                                        double wifi_part =  bit_file_size + download;
                                        if((wifi_part-download_WiFi)<0)
                                        {
                                            download_WiFi = wifi_part;
                                        }
                                        download += bit_file_size;
                                        
                                    }
                                    totaldownload+=download;
                                    totaldownloadbyWiFi+= download_WiFi;
                                    
                                    //cout << "download :" << download << endl;

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
                                // cout << "t2 : " << t2 <<endl;
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
                                    bit_file_size -= download;
                                    if(bit_file_size<0)
                                    {
                                        double wifi_part =  bit_file_size + download;
                                        if((wifi_part-download_WiFi)<0)
                                        {
                                            download_WiFi = wifi_part;
                                        }
                                        download += bit_file_size;
                                        
                                    }
                                    totaldownload+=download;
                                    totaldownloadbyWiFi+= download_WiFi;
                                    //cout << "download :" << download << endl;
                                }
                                

                            }while(tc>0 && bit_file_size>0);
                        }

                    }while(tsi>0 && bit_file_size>0);

                    if(bit_file_size>0)
                    {
                        countMiss++;
                    }

                }

                this->EVo = totaldownloadbyWiFi/(8*((double)N_sim));
                this->EVd = totaldownload/(8*((double)N_sim));
                this->Pmiss = (double)countMiss/(double)N_sim;

                break;
            default:
                break;
        }

    }

};



int main(int argc, char *argv[]) 
{


     
     if (argc < 12) {
		cerr << "Usage: " << argv[0] << " <SIM_ROUND> "<< "<E[Ts]> " << "<E[T0]> " << "<E[Tc]> " << "<E[t1]> " << "<E[t2]> "  \
             << "<CELLULAR_BANDWIDTH> " << "<WIFI_BANDWIDTH> " <<  "<WIFI_BANDWIDTH_1> "  << "<WIFI_BANDWIDTH_2> " << "<FILE_SIZE> " << endl;
		return 1;
	}
    
    int Nsim = atoi(argv[1]);
    double ets = atof(argv[2]);
    double et0 = atof(argv[3]);
    double etC = atof(argv[4]);
    double et1 = atof(argv[5]);
    double et2 = atof(argv[6]);
    double b0 = atof(argv[7]) ;// 4G Mbps
    double b1 = atof(argv[8]) ;// WIFI Mbps
    double r1 = atof(argv[9]) ;// WIFI Mbps
    double r2 = atof(argv[10]) ;// WIFI Mbps
    double file_size = atof(argv[11]); // MB
    
    //cout << "download" <<endl;
/*
    int Nsim = 10000;
    double ets = 180;
    double et0 = 180;
    double etC = 420;
    double et1 = 60;
    double et2 = 360;
    double b0 = 10 ;// 4G Mbps
    double b1 = 5;// WIFI Mbps
    double r1 = 1 ;// 4G Mbps
    double r2 = 5;// WIFI Mbps
    double file_size = 250; // MB
*/
    WiFiRate w1(b0,b1), w2(b0,b1,r1,r2);

    w1.downloadingFile(Nsim,file_size,ets,et0,etC,1);
    w2.downloadingFile(Nsim,file_size,ets,et0,etC,et1,et2,2);

    cout << "============= Report =============" <<endl;
    cout << "Parameter Settings :" <<endl;
    cout << "Nsim :" << Nsim <<endl;
    cout << "E[Ts] :" << ets <<endl;
    cout << "E[T0] :" << et0 <<endl;
    cout << "E[Tc] :" << etC <<endl;
    cout << "E[t1] :" << et1 <<endl;
    cout << "E[t2] :" << et2 <<endl;
    cout << "CELLULAR_BANDWIDTH :" << b0 << " Mbps " <<endl;
    cout << "WIFI_BANDWIDTH :" << b1 << " Mbps " << endl;
    cout << "WIFI_BANDWIDTH r1 :" << r1 << " Mbps " << endl;
    cout << "WIFI_BANDWIDTH r2 :" << r2 << " Mbps " << endl;
    cout << "FILE_SIZE :" << file_size << " MB" <<endl;
    cout << "============= Result =============" <<endl;
    cout <<setw(5) << "# " <<setw(15)<<" Model1(stable) |" << setw(15) << " Model 2(unstable) |" <<endl;
    cout << setw(5) <<left << "P_Miss" << setw(15)<< right  << w1.getPmiss() << setw(15) << right << w2.getPmiss() <<endl;
    cout << setw(5) <<left << "E[Vo]" << setw(15)<< right  << w1.getAverageVolumeWiFi() << setw(15) << right << w2.getAverageVolumeWiFi()<<endl;
    cout << setw(5) <<left << "E[Vd]" << setw(15)<< right  << w1.getAverageVolume() << setw(15) << right << w2.getAverageVolume() <<endl;

    ofstream outfile;
    outfile.open("file_download.txt",ios_base::app);
    string content;
    content += to_string(Nsim)+ "," + to_string(ets) + "," + to_string(et0)+ "," + to_string(etC) + "," + to_string(et1) + "," + to_string(et2)  + ","+ to_string(b0) \
            + ","+ to_string(b1) + "," + to_string(r1) + "," +  to_string(r2) + ","+ to_string(file_size) \
            + "," +  to_string(w1.getPmiss()) + "," +  to_string(w2.getPmiss()) \
            + "," +  to_string(w1.getAverageVolumeWiFi()) + "," +  to_string(w2.getAverageVolumeWiFi()) \
            + "," +  to_string(w1.getAverageVolume()) + "," +  to_string(w2.getAverageVolume()) ;
    outfile << content <<"\n"; 
    outfile.close();
    cout << "Results  are written in file_download.txt" <<endl;

 /*
    vector<double> ts;

    RandomNumber gts(ets);
    RandomNumber gt0(et0);
    RandomNumber gt1(et1);
    RandomNumber gt2(et2);
    RandomNumber gtc(etC);
    RandomNumber ins;

    /*for(int i=0;i<Nsim;i++)
    {
        //ts[i] = GenExpo(ets);
        ts.push_back(gts.getRandomExpo()); 
    }*/
/*
    double plist[2] = {et0/(et0+etC),etC/(et0+etC)};
    int wifistatus = ins.getNumbers(plist,2) ;
    double tsi;
    double tnext = -1;
    double tnext2 = -1;
    int useTnext = 0;
    int useTnext2 = 0;
    int chooseWiFirate = 1;
    int countMiss = 0;
    double downloadVoulume = 0;
    double downloadVoulume_wifi = 0;


    WiFiRate wifi(b0,b1,et1,et2);
    //cout << wifi.getRateWiFi1() << "||" <<wifi.getRateWiFi2() <<endl;

    for(int i=0;i<Nsim;i++)
    {

        double bit_file_size = file_size*8;
        tsi = gts.getRandomExpo();
        //cout << "====ts : " << tsi <<endl;
        double rdownload = 0;
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
                download = wifi.getRateLTE()*t0;
                bit_file_size -= (download);
                if(bit_file_size<0){
                    download += bit_file_size;
                }
                //cout << "download :" << download << endl;
                rdownload+=download;
                downloadVoulume+=download;
                
            }
            else{
                double tc =0;
                double t1 = 0;
                double t2 = 0;
                if(useTnext)
                {
                    tc = tnext;
                } 
                else
                {
                    tc = gt0.getRandomExpo();
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
                    //cout << "tnext c : " << tnext << endl;
                    //cout << "tc for loop : " << tc << endl;
                }
                else{
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
                           // cout << "new t1 : " << t1 <<endl;
                        }
                        else
                        {
                           chooseWiFirate=2;
                           useTnext2 = 0; 
                        }
                        download = (wifi.getRateLTE()+wifi.getRateWiFi1())*t1;
                        download_wifi = (wifi.getRateWiFi1())*t1;
                        bit_file_size -= download;
                        if(bit_file_size<0){
                            download += bit_file_size;
                        }
                        downloadVoulume+=download;
                        rdownload+=download;
                        downloadVoulume_wifi+= download_wifi;
                        
                        //cout << "download :" << download << endl;

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
                       // cout << "t2 : " << t2 <<endl;
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
                        download = (wifi.getRateLTE()+wifi.getRateWiFi2())*t2;
                        download_wifi = (wifi.getRateWiFi1())*t2;
                        bit_file_size -= download;
                        if(bit_file_size<0){
                            download += bit_file_size;
                        }
                        downloadVoulume+=download;
                        rdownload+=download;
                        downloadVoulume_wifi+= download_wifi;
                        //cout << "download :" << download << endl;
                    }
                    

                }while(tc>0 && bit_file_size>0);
                
            }

        }while(tsi>0 && bit_file_size>0);
       // cout << "Remain Size :" << bit_file_size << endl;
        //cout << "dowloaded in this round :" << rdownload << endl; 
        if(bit_file_size>0)
        {
            countMiss++;
           // cout << "count : "<<countMiss<<endl;
        }
    }

    ofstream outfile;
    outfile.open("download.txt",ios_base::app);
    string content;

    cout << "============= Report =============" <<endl;
    cout << "Parameter Settings :" <<endl;
    cout << "Nsim :" << Nsim <<endl;
    cout << "E[Ts] :" << ets <<endl;
    cout << "E[T0] :" << et0 <<endl;
    cout << "E[Tc] :" << etC <<endl;
    cout << "E[t1] :" << et1 <<endl;
    cout << "E[t2] :" << et2 <<endl;
    cout << "CELLULAR_BANDWIDTH :" << b0 << " Mbps " <<endl;
    cout << "WIFI_BANDWIDTH :" << b1 << " Mbps " << endl;
    cout << "FILE_SIZE :" << file_size << " MB" <<endl;
    cout << "============= Result =============" <<endl;
    double deadlineRaito = (double)countMiss/(double)Nsim;
    double EVD = downloadVoulume/(8*Nsim);
    double EVO = downloadVoulume_wifi/(8*Nsim);
    cout << "Deadline MissRatio :" << deadlineRaito <<endl;
    cout << "E[Vd] =" << EVD <<endl;
    cout << "E[Vo] =" << EVO <<endl;
    cout << "==================================" <<endl;
    content += to_string(Nsim)+ "," + to_string(ets) + "," + to_string(et0)+ "," + to_string(etC) + "," + to_string(et1) + "," + to_string(et2)  + ","+ to_string(b0) \
            + ","+ to_string(b1) + ","+ to_string(file_size) + "," +  to_string(deadlineRaito) + "," +  to_string(EVD) + "," +  to_string(EVO);
    outfile << content <<"\n"; 
    outfile.close();
    cout << "Results  are written in download.txt" <<endl;
*/
    return 0;
}