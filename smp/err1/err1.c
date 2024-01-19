// err1.c: This should fail with duplicate labels due to lenght of 8!
// works with z390
// fails with MVT (as it should)
int xxxxxxxxa = 1;
int xxxxxxxxb = 2;
int xxxxxxxxc;
int main() {
   if (xxxxxxxxa == xxxxxxxxb) {
     xxxxxxxxc =  1;
   } else {
     xxxxxxxxc = 0;
   }
   return xxxxxxxxc;
}
