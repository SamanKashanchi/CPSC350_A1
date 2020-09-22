#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include<cstdlib>
#include<ctime>
using namespace std;

 int main(int argc,char* argv[]) {
 char ans = 'N';
//While loop for prompting user again
 do {

  if (argc > 1) {
    cout << "You Have entered: " << argv[1] <<". Preparing output file. " <<endl;
      }
  else {
    cout << "No file name entered."<< "\n";
    return -1;
      }
  ifstream txtF(argv[1]);


// making varibles for stats
  double linecounter = 0;
  double charcounter = 0;
  double mean = 0;
  double variance =0;
  double std;

  int Acounter;
  int AAcounter;
  int ACcounter;
  int ATcounter;
  int AGcounter;

  int Ccounter;
  int CAcounter;
  int CCcounter;
  int CTcounter;
  int CGcounter;

  int Tcounter;
  int TAcounter;
  int TCcounter;
  int TTcounter;
  int TGcounter;

  int Gcounter;
  int GAcounter;
  int GCcounter;
  int GTcounter;
  int GGcounter;

//error checking
  if(!txtF){
    cout << "Error: There is no such file"<<"\n";
    exit(0);
  }

//looking at every line
  string Curline;
  while(getline(txtF, Curline)){

     linecounter++;
     charcounter += Curline.length();
//looking at every char
     for(int i = 0; i<Curline.length(); i++){

//counting letter and pairs
       if (Curline.at(i) == ' ') {
       charcounter--;
      }
       toupper(Curline[i]);
       if(Curline.at(i) == 'A' || Curline.at(i) == 'a'){
        Acounter++;

        if (i<(Curline.length()-1)){

          if (Curline.at(i+1) == 'A' || Curline.at(i) == 'a'){
            AAcounter++;
          }
          else if (Curline.at(i+1) == 'C' || Curline.at(i) == 'c'){
            ACcounter++;
          }
          else if (Curline.at(i+1) == 'T' || Curline.at(i) == 't'){
            ATcounter++;
          }
          else if (Curline.at(i+1) == 'G' || Curline.at(i) == 'g'){
            AGcounter++;
          }
        }
      }


       if(Curline.at(i) == 'C' || Curline.at(i) == 'c'){
        Ccounter++;
        if (i<(Curline.length()-1)){

          if (Curline.at(i+1) == 'A' || Curline.at(i) == 'a'){
            CAcounter++;

          }
          else if (Curline.at(i+1) == 'C' || Curline.at(i) == 'c'){
            CCcounter++;
          }
          else if (Curline.at(i+1) == 'T' || Curline.at(i) == 't'){
            CTcounter++;
          }
          else if (Curline.at(i+1) == 'G' || Curline.at(i) == 'g'){
            CGcounter++;
          }
        }
      }


       if(Curline.at(i) == 'T' || Curline.at(i) == 't'){
        Tcounter++;
        if (i<(Curline.length()-1)){

          if (Curline.at(i+1) == 'A' || Curline.at(i) == 'a'){
            TAcounter++;

          }
          else if (Curline.at(i+1) == 'C' || Curline.at(i) == 'c'){
            TCcounter++;
          }
          else if (Curline.at(i+1) == 'T' || Curline.at(i) == 't'){
            TTcounter++;
          }
          else if (Curline.at(i+1) == 'G' || Curline.at(i) == 'g'){
            TGcounter++;
          }
        }
      }


       if(Curline.at(i) == 'G' || Curline.at(i) == 'g'){
        Gcounter++;
        if (i<(Curline.length()-1)){

          if (Curline.at(i+1) == 'A' || Curline.at(i) == 'a'){
            GAcounter++;

          }
          else if (Curline.at(i+1) == 'C' || Curline.at(i) == 'c'){
            GCcounter++;
          }
          else if (Curline.at(i+1) == 'T' || Curline.at(i) == 't'){
            GTcounter++;
          }
          else if (Curline.at(i+1) == 'G' || Curline.at(i) == 'g'){
            GGcounter++;
          }
        }
     }



     }
  }
//calculating stats
  mean = charcounter/linecounter;

  txtF.close();

  fstream txtF2;
  txtF2.open( argv[1]);
  double sigma;
  string Curline2;
  while(getline(txtF2, Curline2)){ //read data from file object and put it into string.

     sigma += pow(Curline2.length() - mean, 2);

   }


  variance = sigma/linecounter;
  std = sqrt(variance);
  txtF2.close();


  ofstream OutputFile("SamanKashanchi.out");

  OutputFile << "Name: Saman Kashanchi" << '\n';
  OutputFile << "Student ID: 2301023" << '\n';
  OutputFile << "The Sum of the length of the DNA strings is: " << charcounter << '\n';
  OutputFile<<"The Mean of the length of the DNA strings is: "<< mean<< '\n';
  OutputFile<<"The variance of the length of the DNA strings is:  "<< variance<< '\n';
  OutputFile<<"The Standard Deviation of the length of the DNA stings is: "<< std << '\n';
  OutputFile << "Here is the relative probability of each nucleotide: " << '\n';
  OutputFile<< "A: "<< Acounter/charcounter << '\n';
  OutputFile<< "C: "<< Ccounter/charcounter << '\n';
  OutputFile<< "T: "<< Tcounter/charcounter << '\n';
  OutputFile<< "G: "<< Gcounter/charcounter << '\n';
  OutputFile << "Here is the relative probability of each nucleotide bigram: " << '\n';
  OutputFile<< "AA: "<< AAcounter/(charcounter/2) << '\n';
  OutputFile<< "AC: "<< ACcounter/(charcounter/2) << '\n';
  OutputFile<< "AT: "<< ATcounter/(charcounter/2) << '\n';
  OutputFile<< "AG: "<< AGcounter/(charcounter/2) << '\n';
  OutputFile<< "CA: "<< CAcounter/(charcounter/2) << '\n';
  OutputFile<< "CC: "<< CCcounter/(charcounter/2) << '\n';
  OutputFile<< "CT: "<< CTcounter/(charcounter/2) << '\n';
  OutputFile<< "CG: "<< CGcounter/(charcounter/2) << '\n';
  OutputFile<< "GA: "<< GAcounter/(charcounter/2) << '\n';
  OutputFile<< "GC: "<< GCcounter/(charcounter/2) << '\n';
  OutputFile<< "GT: "<< GTcounter/(charcounter/2) << '\n';
  OutputFile<< "GG: "<< GGcounter/(charcounter/2) << '\n';
  OutputFile<< "TA: "<< TAcounter/(charcounter/2) << '\n';
  OutputFile<< "TC: "<< TCcounter/(charcounter/2) << '\n';
  OutputFile<< "TT: "<< TTcounter/(charcounter/2) << '\n';
  OutputFile<< "TG: "<< TGcounter/(charcounter/2) << '\n';

//generating random with time seeded
//String array for saving out put to
  string sampleString[1000] = {};
  srand( (unsigned)time( NULL ) );
  for(int i = 0; i < 1000; i++){
//Gaussian distribution
    double a;
    double b;
    a = (float) rand()/RAND_MAX;
    b = (float) rand()/RAND_MAX;
    double c = (double)sqrt(-2 * log(a)) * (double)cos(2*M_PI*b);
    double d = std* c + mean;
//appending baced on possibility
    for(int j =0; j < d; j++){
      double e;
      e = (float) rand()/RAND_MAX;

      if (e <= (Acounter/charcounter)){
        sampleString[i].append("A");
      }
      else if (e <= (Acounter+Ccounter)/charcounter) {
        sampleString[i].append("C");
      }
      else if (e <= ((Acounter+Ccounter+Gcounter)/charcounter)) {
        sampleString[i].append("G");
      }
      else {
        sampleString[i].append("T");
      }

        }
        OutputFile << sampleString[i]<<endl;

         }
        std::cout << "The ouput file has been created with success. " << '\n';


        cout << "Please Enter another txt file fallowed by a letter if you wish to continue with your analysis. Or Q to quit.\n";

        char letter;
        cin >> letter;

         if(letter == 'q'|| letter == 'Q'){
          exit(0);
        }
        cin >> argv[0]>>ans;


      }while((ans));


}
