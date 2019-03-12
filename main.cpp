#include <iostream>
#include <typeinfo>

using namespace std;
class data
{
    int an;
    int luna;
    int zi;
public:
    int get_zi()
    {
        return zi;
    }
    int get_luna()
    {
        return luna;
    }
    int get_an()
    {
        return an;
    }
    void citire()
    {
        cout<<"zi:"<<endl; cin>>zi;
        cout<<"luna:"<<endl;cin>>luna;
        cout<<"an:"<<endl; cin>>an;
    }
    void afisare()
    {
        cout<<"Pe data de "<<zi<<"."<<luna<<"."<<an<<" ";
    }
    friend class Lot;
};
class Produs
{protected:
    string unitate_mas;
    string nume_produs;

public:
    void set_nume(string name)
    {
        nume_produs=name;
    }string get_nume()
    {
        return nume_produs;
    }


    string get_unitatedemasura()
    {
        return unitate_mas;
    }
    virtual void citire()
    {
        cout<<"Citeste unitate de masura"<<endl;
        cin>>unitate_mas;
        cout<<"Nume produs:"<<endl;
        cin>>nume_produs;
    }
    virtual void afisare()
    {
        cout<<unitate_mas<<" de "<<nume_produs<<" ";
    }
    friend class Lot;

};
class Produs_Perisabil:public Produs
{
    int perioada_de_valab;
    public:

        Produs_Perisabil()
        {
            cout<<"xxxxxx"<<endl;
        }
        void citire()
        {
         Produs::citire();
         cout<<"Perioada de valabilitate: "<<endl;
         cin>>perioada_de_valab;
        }
        void afisare()
        {
            Produs::afisare();
            cout<<", cu perioada de valabilitate de "<<perioada_de_valab<<" zile ";
        }
};
class Produs_la_promotie:public Produs
{
    int discount;
public:
    Produs_la_promotie()
    {
        cout<<"yyyyyyyyyyy"<<endl;
    }
    int get_Discount()
    {
        return discount;
    }
    void citire()
    {
        Produs::citire();
        cout<<"Discount"<<endl;
        cin>>discount;
    }
    void afisare()
    {
        Produs::afisare();
        cout<<" ,la care decide sa aplice un discount de "<<discount<<"%"<<endl;
    }

};
class Lot
{
    int cantitate;
    int pret_intrare;
    int pret_vanzare;

    data d;
    data dexp;
    Produs*p;
    public:
        int get_pret_vanzare()
        {
            return pret_vanzare;
        }
         void Calc_PretVanzare()
         {
           if(typeid(*p).name()==typeid(Produs_la_promotie).name()){ Produs_la_promotie*ppl=dynamic_cast<Produs_la_promotie*>(p);
             pret_vanzare=pret_intrare-((ppl->get_Discount()*pret_intrare)/100);}
             else {

                pret_vanzare=pret_intrare/2.0;
             }

         }

        /*Lot()
        {
            cout<<"////Lotul este/////"<<endl;

        }*/
       /* virtual ~Lot()
        {

        }*/
        void citire()
        {
            int tip;
            cout<<"Citeste tipul de produs"<<endl;
            cin>>tip;
            if(tip==0) p=new Produs_Perisabil();
             else if(tip==1) p=new Produs_la_promotie();
             cout<<"Date lot"<<endl;
             cout<<"Cantitate:"<<endl;
             cin>>cantitate;
             cout<<"Pret de intrare:"<<endl;
             cin>>pret_intrare;

             this->d.citire();
             cout<<"Data exp lot:"<<endl;
             this->dexp.citire();
             p->citire();





        }
        void afisare()
        { d.afisare();
            cout<<"magazinul primeste un lot de "<<cantitate<<" ";

            p->afisare();
            Calc_PretVanzare();
            cout<<" ,la pretul de "<<pret_vanzare<<" lei pe "<<p->get_unitatedemasura()<<endl;
        }
        int data_buna(data d1,data d2)
        {
           if(d1.get_an()<d2.get_an())
           {
               if(d.an<d2.get_an()&& d.an>d1.get_an()) return 1;


           }
           if(d1.get_an()==d2.get_an())
           {
               if(d.luna<=d2.get_luna()&&d.luna>=d1.get_luna()) return 1;
           }
           return 0;
        }
        int data_nu_expirat()
        {
            if(d.an<dexp.an) return 1;
            if(d.an==dexp.an && d.luna<dexp.luna) return 1;
            return 0;
        }
        int nume_corect( string xxx)
        {
            if(p->nume_produs==xxx) return 1;
            return 0;
        }
        int cant_buna( int x)
        {
            if(this->cantitate<=x) return 1;
            return 0;
        }



};

int main()
{
    Lot lista[30];
    int n;
    cout<<"Nr loturi:"<<endl;
    cin>>n;

    for(int i=0;i<n;i++)
       {

        //lista[i]=new Lot();
        lista[i].citire();
        lista[i].afisare();
       } /////////// merge cu vector simplu de loturi nu trb dublu pointer

       int optiune;
       cout<<"Optiunea este:"<<endl;
       cin>>optiune;
       switch(optiune)
       { case 1:{  Produs**pr;

       int yyy;
       cout<<"Citeste nr de produse:"<<endl;
       cin>>yyy;
       pr = new Produs*[yyy];

       for(int i=0;i<yyy;i++)
       { int tip_pr;


       cout<<"Tipul produsului dorit este:"<<endl;
       cin>>tip_pr;
       if(tip_pr==5) pr[i]=new Produs_Perisabil();
       else if(tip_pr==6) pr[i]=new Produs_la_promotie();
     pr[i]->citire();


       }


       yyy++;
       cout<<"Ce tip de produs adaugati? pp sau plp"<<" ";
       string tippr;
       cin>>tippr;
       if(tippr=="pp") pr[yyy-1]=new Produs_Perisabil();
       else if(tippr=="plp") pr[yyy-1]=new Produs_Perisabil();
       pr[yyy-1]->citire();
        for(int b=0;b<yyy;b++)
            pr[b]->afisare();


       break;




       }
   case 2:
    {
        int n;
        Produs ppp[20];
        cout<<"Nr produse:"<<endl;
        cin>>n;

        for(int i=0;i<n;i++)
        { string nn;
        cout<<"Nume pr:"<<endl;
        cin>>nn;
        ppp[i].set_nume(nn);


        }
        cout<<"Produsele sunt:"<<endl;
        for(int j=0;j<n;j++)
             cout<<ppp[j].get_nume()<<" ";
        break;
    }
   case 3:
    {  Lot**lista;
    int nrLot;

    cout<<"Nr loturi:"<<endl;
    cin>>nrLot;
    lista=new Lot*[nrLot];

    for(int i=0;i<nrLot;i++)
       {

        lista[i]=new Lot();
        lista[i]->citire();



    }
    cout<<"Adaugare lot nou"<<endl;


    nrLot++;
     lista[nrLot-1]->citire();
      for(int k=0;k<nrLot;k++)
     lista[k]->afisare();
     break;
    }
   case 4:
    {
        Lot*lista[30];
    int nrLot;
    cout<<"Nr loturi:"<<endl;
    cin>>nrLot;

    for(int i=0;i<nrLot;i++)
       {

        lista[i]=new Lot();
        lista[i]->citire();



    }
    data d1,d2;
    cout<<"prima data:"<<endl;
    d1.citire();
    cout<<"a doua data data:"<<endl;
    d2.citire();
    for(int z=0;z<nrLot;z++)
    {  cout<<"Loturile aflate in perioada de valabilitate sunt:"<<endl;
        if(lista[z]->data_buna(d1,d2)==1) lista[z]->afisare();
    }

 break;
    }








       };


    return 0;
}
