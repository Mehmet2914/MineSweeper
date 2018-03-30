// Mehmet MUTLU - 20130855031 - Elektrik/Elektronik Muhendisligi - 2. Ogretim
// Basit Mayin Tarlasi oyunu
#include<stdio.h>  
#include<stdlib.h>   
                  
void giris();
void rstmayin(char anadizi[12][12]);
void matrisyazma(char anadizi[12][12],int r,char yardizi[12][12]);
int asama(char anadizi[12][12],int r,int c,char yardizi[12][12]);

int main()

{                   
char anadizi[12][12] = {{'0'}};      // ana dizinin degerlerini arttirma islemini kolay yapabilmek icin 0 yapiyoruz
int i,r,c;   							// kullandigimiz integerleri atadik
char yardizi[12][12] = {{'0'}};		

// giris();   
    
 rstmayin(anadizi);  		// rastgele mayin dosedigimiz fonksiyonu ana fonksiyonda cagiriyoruz

  // kulanicidan 1 ve 11 arasinda bir deger istiyoruz  
  
  
  printf("		MAYIN TARLASI OYUNU ");
  // girdiginiz degeri satir (enter) sutun (enter) olarak giriniz
  printf("\nSecmis oldugunuz satir ve sutun degerlerini giriniz \n");
  scanf("%d%d",&r,&c);			// degeri okuyoruz
 
              matrisyazma(anadizi,12,yardizi);  // fonksiyon cagirarak girilen satir ve sutunu denetliyoruz
 
 i = asama(anadizi,r,c,yardizi); // 1 degerleri mayin olmayan yerlere 0 degleri mayin olanlara atanacak
  
     
  while(i == 1)     			// eger secilen satir ve sutun degerinde mayin yoksa donguye giriyoruz
   {
     printf("Lutfen tekrar satir ve sutun degeri giriniz\n");      
     printf(" %c Etrafindaki mayinlar\n\n",anadizi[r][c]);		// satir ve sutun degerinin etrafindaki mayinlari giriyoruz
     
     matrisyazma(anadizi,12,yardizi); 
     
     printf("Tekrar satir ve sutun degeri giriniz ");		// kullanici mayin bulmadigi icin tekrar deger istiyoruz
     scanf("%d%d",&r,&c);				// degeri okuyoruz
     i=0; 
     
     i = asama(anadizi,r,c,yardizi);    // i degerini tekrar degistiriyoruz
   
   
   }  

  if(i==0)									// kullanici mayini buldugu icin  program sonlandiyoruz 
   printf("Mayina bastiniz ! Oyun bitti\n");

return 0;    
    
}



void rstmayin(char anadizi[12][12])				// simdi ana dizimize rastgele random komutu ile mayin atayacagiz

{
    
int r,c,m;

    
 
 for(m=0;m<20;m++) // 20 rastgele mayin atayacak
     
  {
   r = rand() % 13; // mayin yerlestiriliyor   
                    
   c = rand() % 13; // 1-13 arasinda atamak en uygun sonucu verdigi icin boyle sectim
    
   
   anadizi[r][c] = '9'; // rastgele atadigimiz satir ve sutun degerini 9 karakterine atiyoruz yani mayini temsil ediyor
  
  
  }  
    
return;

}
// simdi ekranda gorulmesi gereken yardimci diziyi yazdiracagiz
void matrisyazma(char anadizi[][12],int r,char yardizi[12][12])			
{
    
int i,j;    
 
printf("------------------------------  \n");			// oynun daha estetik gorulmesi icin bu printfleri kullandim

 for(i=1;i<r;i++)							// fonksiyonla cagirdigimiz r degerine kadar dongumuzu donduruyoruz
  {
   printf("----");							

   for(j=1;j<12;j++) //1 den 11 e kadar yazdiriyoruz  
    {
     printf("%c ",yardizi[i][j]);//degerleri yardimcidiziye gonderiyoruz
    } 
   
   printf("----");							// kac tane cizgi atayacagimiz deneme yanilma ile buldum
   
   printf("\n");   
  
  }

printf("------------------------------\n\n");

return;    
}

int asama(char anadizi[12][12],int r,int c,char yardizi[12][12])
{
    
 int i=r,j=c,b=0,k;    
 char C;

 if(anadizi[r][c] == '9')   			// eger ana dizideki eleman 9 ise direk 0 yaziyoruz
 {  k=0;
   return k;
 }
 else								// eger 9 degilse yukari-asagi-sag-sol-capraz degerleri 1 arttirarak yaziyoruz
  {
   if(anadizi[i-1][j-1] == '9')    
    b++;  
   if(anadizi[i-1][j] == '9')    
    b++;  
   if(anadizi[i-1][j+1] == '9')    
    b++;  
   if(anadizi[i][j-1] == '9')    
    b++;  
   if(anadizi[i][j+1] == '9')    
    b++;  
   if(anadizi[i+1][j-1] == '9')    
    b++;  
   if(anadizi[i+1][j] == '9')    
    b++;  
   if(anadizi[i+1][j+1] == '9')    
    b++;  
  
  C = (char)(((int)'0')+b); // char komutunun icine sakliyoruz;

   anadizi[r][c] = C;		// ana diziyi yardimci diziye atiyoruz
   yardizi[r][c] = C;
  
  }
    
 return 1;  
    
}
