#include "Masa.h"
#include "Ciorba.h"
#include "Fel_principal.h"
#include "Bautura.h"
#include "Desert.h"
#include "Client.h"

using namespace std;

int main()
{
    Masa m1(10),m2(4),m3(20);
    m1.ocupa_masa(5);
    m2.ocupa_masa(2);
    m3.ocupa_masa(8);
    m1.elibereaza_masa();
    cout<<m3;
    Ciorba c1("  cioRBA  De  cIUPercI    ",true,true);
    //cout<<c1;
    Fel_principal f1("Chateaubriand","  caRtoFi ","prajiti","stroganoff");
    Fel_principal f2(" frigarui");
    Fel_principal f3("Tocana","Orez sarbesc","");
    Bautura b1("  vin varsat  ","  Rosu",500);
    Bautura b2("Sticla vin","Castel Bolovanu 2004",2);
    Bautura b3("Sticla bere",2);
    Desert d1("  tort KranTZ ");
    Desert d2(" inghetATA ",4);
    //Client cl1(c1,f1,d1,b1);
    Client cl1(&c1,&f1,&d1,&b1);
    cout<<cl1;
    Client cl2=cl1;//m-am gandit ca exista cazul in care doi clienti comanda aceleasi produse
    cl2.schimba_desert(d2);//de asemenea, am facut metodele de schimba in cazul in care un client de razgandeste asupra unui produs
    cl2.schimba_fel_principal(f3);
    cl2.schimba_bautura(b2);
    cout<<cl2;
    return 0;
}