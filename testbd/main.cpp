#include <iostream>
#include <winsock.h>

#define __WIN__
#include "MYSQL/mysql.h"

using namespace std;

int saisie()
{
    int n=0;
    bool trv=false;
    do{
        try{
             cin>>n;
             trv=true;
        }catch(exception ex)
        {
            cout<<"Erreur de saisie veuillez resaisir"<<endl;
            trv=false;
        }
   }while(trv==false);
   return n;
}

int main()
{

MYSQL *conn;
   conn = mysql_init(NULL);

   if (!mysql_real_connect(conn, "127.0.0.1", "root", "", "compte", 0, NULL, 0)) {
       cout<<"la connection a échoué"<<endl;
    }
    else {
            //cout<<"la connection a réussi"<<endl;
            MYSQL_ROW myROW; //Elle permet de reccupere une ligne
            MYSQL_RES *res; ////Elle permet de reccupere les element de la table

       int Rep;
      do{
        system("CLS");
        cout << "       @@--$$--**--##--@***@***@--##--**--$$--@@" << endl;
        cout << "           1 : Ajouter un compte courant " << endl;
        cout << "           2 : Ajouter un compte epargne" << endl;
        cout << "           3 : Ajouter un compte bloque" << endl;
        cout << "           4 : Rechercher par type de compte" << endl;
        cout << "           0 : Quitter " << endl;
        int chx;
        cout << "           Faitez votre choix :" << endl;
        chx=saisie();
        int rep;
        string solde,mat,prop,dateouv,soldemin,depot,mtprelevement,Datedebit,Datefin;

        int jour,mois,an;
        switch(chx)
        {
            case 1 :
                     system("CLS");
                     do{
                          cout << " Ajouter un compte courant" << endl;
                          cout<<"Numero Compte Courant : ";cin>>mat;
                          cout<<"Proprietaire Compte Courant : ";cin>>prop;
                          cout<<"Annee Mois Jour couverture compte ";cin>>dateouv;
                          //dateouv=an+"-"+mois+"-"+jour;
                          cout<<"Solde Compte Courant : ";cin>>solde;
                        string requete= "INSERT INTO courant(numcompte ,proprietaire ,dateOuverture ,sold)VALUES ('"+mat+"', '"+prop+"', '"+dateouv+"', '"+solde+"')";
                        if(( mysql_query(conn,requete.c_str()) == 0))
                                {
                                    cout<<"Insertion ok "<<endl;
                                }
                                else
                                    cout<<"Insertion no ok "<<endl;
                        cout<<"Voulez vous ajouter en autre 1 ou 0"<<endl;
                        rep=saisie();
                     }while(rep==1); break;
            case 2 :
                     system("CLS");
                     do{
                            cout << " Ajouter un compte epargne " << endl;

                          cout<<"Numero Compte Courant : ";cin>>mat;
                          cout<<"Proprietaire Compte Courant : ";cin>>prop;
                          cout<<"Annee Mois Jour couverture compte ";cin>>dateouv;
                          cout<<"solde c ";cin>>solde;
                          cout<<"solde min";cin>>soldemin;

                        string requetes= "INSERT INTO epargne(numcompte ,proprietaire ,dateOuverture ,sold,soldmin)VALUES ('"+mat+"', '"+prop+"', '"+dateouv+"', '"+solde+"','"+soldemin+"')";
                        if(( mysql_query(conn,requetes.c_str()) == 0))
                                {
                                    cout<<"Insertion ok "<<endl;
                                }
                                else
                                    cout<<"Insertion no ok "<<endl;

                        cout<<"Voulez vous ajouter en autre 1 ou 0"<<endl;
                        rep=saisie();
                     }while(rep==1); break;
            case 3 :
                     system("CLS");
                     do{
                         cout << " Ajouter un compte bloque " << endl;
                          cout<<"Numero Compte Courant : ";cin>>mat;
                          cout<<"Proprietaire Compte Courant : ";cin>>prop;
                          cout<<"Annee Mois Jour couverture compte ";cin>>dateouv;
                          cout<<"solde c ";cin>>solde;
                          cout<<"date debit";cin>>Datedebit;
                          cout<<"date fin";cin>>Datefin;

                         string REQUETEE= "INSERT INTO bloque(numcompte ,proprietaire ,dateOuverture ,sold,Datedebit,Datefin)VALUES ('"+mat+"', '"+prop+"', '"+dateouv+"', '"+solde+"','"+Datedebit+"','"+Datefin+"')";
                         if(( mysql_query(conn,REQUETEE.c_str() ) == 0))
                                {
                                    cout<<"Insertion ok "<<endl;
                                }
                                else
                                    cout<<"Insertion no ok "<<endl;

                        cout<<"Voulez vous ajouter en autre 1 ou 0"<<endl;
                        rep=saisie();
                     }while(rep==1); break;

            case 4 :

                     do{
                            system("CLS");
                        cout << "Choisir un type de compte :  "<< endl<<"       1: Courant "<<
                                endl<<"       2: Epargne "<< endl<<"       3: Bloque" << endl;
                        int chxp=saisie();

                             if(chxp==1)
                             {
                                system("CLS");
                               if(( mysql_query(conn, "SELECT * FROM courant") == 0))
                                {
                                  res= mysql_store_result(conn);
                                 while ((myROW = mysql_fetch_row(res)))
                                    {

                                       //unsigned long *lengths;

                                        //On stocke ces tailles dans le pointeur
                                       int  lengths = mysql_num_fields(res);

                                        //On fait une boucle pour avoir la valeur de chaque champs
                                        for(int i = 0; i < (int)lengths; i++)
                                        {
                                           //Affichage des elt de la ligne
                                           cout<<" "<<myROW[i]<<endl;

                                        }
                                    }
                                }
                             }
                             if(chxp==2)
                             {
                                system("CLS");
                               if(( mysql_query(conn, "SELECT * FROM epargne") == 0))
                                {
                                  res= mysql_store_result(conn);
                                 while ((myROW = mysql_fetch_row(res)))
                                    {

                                       //unsigned long *lengths;

                                        //On stocke ces tailles dans le pointeur
                                       int  lengths = mysql_num_fields(res);

                                        //On fait une boucle pour avoir la valeur de chaque champs
                                        for(int i = 0; i < (int)lengths; i++)
                                        {
                                           //Affichage des elt de la ligne
                                           cout<<" "<<myROW[i]<<endl;

                                        }
                                    }
                                }
                             }
                             if(chxp==3)
                             {
                                 system("CLS");
                               if(( mysql_query(conn, "SELECT * FROM bloque") == 0))
                                {
                                  res= mysql_store_result(conn);
                                 while ((myROW = mysql_fetch_row(res)))
                                    {

                                       //unsigned long *lengths;

                                        //On stocke ces tailles dans le pointeur
                                       int  lengths = mysql_num_fields(res);

                                        //On fait une boucle pour avoir la valeur de chaque champs
                                        for(int i = 0; i < (int)lengths; i++)
                                        {
                                           //Affichage des elt de la ligne
                                           cout<<" "<<myROW[i]<<endl;

                                        }
                                    }
                                }
                             }

                        cout<<"Voulez vous rechercher par profil autre 1 ou 0"<<endl;
                        rep=saisie();
                     }while(rep==1);break;
            case 0 : cout<<"*********AU REVOIR **********"<<endl;
                     exit(-1);
            default: cout<<"Lien introuve "<<endl;
        }

        cout << "Voulez vous revenir au menu 1 ou 0" << endl;
        Rep=saisie();
    }while(Rep==1);
      }
    return 0;
}

