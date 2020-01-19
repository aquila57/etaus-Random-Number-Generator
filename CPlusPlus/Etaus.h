class Etaus {
   public:
      Etaus();
      unsigned int etaus(void);
      unsigned int get_etaus(void);
      double get_dbl_etaus(void);
      int get_etaus_int(int lmt);
      unsigned int get_etaus_pwr(int bits);
      void display(void);

   protected:
      // other classes go here...

      private:
      unsigned int s1;
      unsigned int s2;
      unsigned int s3;
      unsigned int s;
      unsigned int prev;
      unsigned int pprev;
      unsigned int out;
      unsigned int mask;
      unsigned int state[16384];
      double maxint;
   }; // class etaus
