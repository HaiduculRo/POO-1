#include <iostream>
#include <cstring>
using namespace std;
class Papuci{
private:
    static int contProd;
    const int idProd;
    char *brand; ///{Adidas}
    string model;
    float size;
    int stoc;
    float pret;
public:
    ///cosntructorii
    Papuci();
    Papuci(char *brand, string model, float size, int stoc, float pret);
    Papuci(const Papuci& Obj);
    ///operatori
    Papuci& operator=(const Papuci& Obj);
    Papuci& operator-(float Obj);
    Papuci& operator+(const float &Obj);
    Papuci& operator*(const float &Obj);
    Papuci& operator++();
    Papuci operator++(int);
    bool operator ==(const Papuci &obj);
    bool operator >(const Papuci &obj);
    operator string();///explicit
    ///functii friend
    friend ostream& operator <<(ostream& out, const Papuci& c1);
    friend istream& operator >>(istream& in,  Papuci& obj);
    friend void afisare2(const Papuci &Obj);
    friend Papuci operator+(int x, Papuci &obj);
    friend Papuci operator*(int x, Papuci &obj);
    ///getteri
    string getBrand(){return this->brand;}
    string getModel(){return this->model;}
    int static getContProd(){return Papuci::contProd;}
    int const getIdPapuci(){return this->idProd;}
    float getSize(){return this->size;}
    int getStoc() {return this->stoc;} /// cand folosesc const ?
    float getPret(){return this->pret;}
    ///functii
    void afisare();
    void citire();
    ///setari
    void setBrand(char *x){
        if(this->brand!=NULL)
        {
            delete[] this->brand;
            this->brand=NULL;
        }
        this->brand=new char[strlen(x)+1];
        strcpy(this->brand, x);
    }
    void setModel(string x){this->model =x;}
    void setSize(float x){this->size = x;}
    void setStoc(int x) {this->stoc = x;}
    void setPret(float x){this->pret = x;}
    ///void setNrLansari(int x){this->nrLansari = x;}
    /// destructor
    ~Papuci(){
        if(this -> brand != NULL){
            delete[] this->brand;
            this->brand = NULL;
        }
    }
};
int Papuci::contProd=1000;
Papuci& Papuci::operator=(const Papuci &Obj) {
    if(this != &Obj) {
        if (this->brand != NULL) {
            delete[] this->brand;
            this->brand = NULL;
        }

        this->brand = new char[strlen(Obj.brand) + 1]; ///memorie alocata
        strcpy(this->brand, Obj.brand); /// atribuire valoare
        this->model = Obj.model;
        this->size = Obj.size;
        this->stoc = Obj.stoc;
        this->pret = Obj.pret;
    }
    return *this;
}

void Papuci::afisare(){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Papuci: " << this->idProd<<endl;
    cout << "brand: " <<this->brand<<endl;
    cout << "model: " <<this->model<<endl;
    cout << "Marime: "<< this->size <<endl;
    cout << "Stoc: " << this->stoc <<endl;
    cout << "Pret: " << this->pret <<endl;
}
void afisare2(const Papuci& Obj){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Papuci: " << Obj.idProd<<endl;
    cout << "brand: " << Obj.brand<<endl;
    cout << "model: " << Obj.model<<endl;
    cout << "Marime: "<< Obj.size <<endl;
    cout << "Stoc: " << Obj.stoc <<endl;
    cout << "Pret: " << Obj.pret <<endl;
}
/// >> <<
ostream& operator <<(ostream& out, const Papuci& c1){
    out<< "Afisare Pereche Papusci : " <<endl;
    out<<"-----------------------------"<<endl;
    out << "id Papuci: " << c1.idProd<<endl;
    out << "brand: " <<c1.brand<<endl;
    out << "model: " <<c1.model<<endl;
    out << "Marime: " <<c1.size<<endl;
    out << "Stoc: " <<c1.stoc<<endl;
    out << "Pret: " <<c1.pret<<endl;
    return out;
}
istream& operator >>(istream& in,  Papuci& obj){
    cout<<"Brand: ";
    char aux[100];
    in >> aux;
    if(obj.brand != NULL){
        delete[] obj.brand;
    }
    obj.brand = new char[strlen(aux)+1];
    strcpy(obj.brand, aux);

    cout << "Model: ";
    in >> obj.model;

    cout << "Size: ";
    in >> obj.size;

    cout << "Stoc: ";
    in >> obj.stoc;

    cout << "Pret: ";
    in >> obj.pret;
    return in;

}
void Papuci::citire(){

    cout << "Afisare informatii relevante: " << endl;

    cout << "Brand: ";
    char aux[100];
    cin >> aux;
    if(this->brand != NULL){
        delete[] this->brand;
    }
    this->brand = new char[strlen(aux)+1];
    strcpy(this->brand, aux);

    cout << "Model: ";
    cin >> this->model;

    cout << "Size: ";
    cin >> this->size;

    cout << "Stoc: ";
    cin >> this->stoc;

    cout << "Pret: ";
    cin >> this->pret;

    cout << endl;
}
///adunare
Papuci& Papuci::operator+(const float & Obj){
    this->pret = this->pret + Obj;
    return *this;
    }

///float + adunare ???


Papuci& Papuci::operator-(float Obj){
    this->pret = pret - Obj;
    return *this;
}

Papuci& Papuci::operator*(const float & Obj){
    this->pret = pret * Obj;
    return *this;
}
Papuci& Papuci::operator++(){
    this->stoc = stoc + 10 ;
    return *this;
}
Papuci Papuci::operator++(int){
    Papuci aux(*this);
    operator++();
    return aux;
}
Papuci operator+(int x, Papuci &obj){
    return obj+x;
}
Papuci operator*(int x, Papuci &obj){
    return obj*x;
}
bool Papuci::operator==(const Papuci& obj) {
    return strcmp(this->brand,obj.brand)==0 and this->model.compare(obj.model)==0 and this->size==obj.size and this->stoc==obj.stoc and this->pret==obj.pret;
}
bool Papuci::operator>(const Papuci& obj){
    return this->pret > obj.pret;
}
Papuci::operator string(){
    return this->model;
}
///initializabre_anonim
Papuci::Papuci():idProd(contProd++){ ///initializare_anonim
    brand = new char[strlen("Anonim")+1];
    strcpy(brand,"Anonim");
    model = "Anonim";
    size = 0;
    stoc = 0;
    pret = 0;
}
///constructor
Papuci::Papuci(char *brand, string model, float size, int stoc, float pret):idProd(contProd++){
    this->brand = new char[strlen(brand)+1]; ///memorie alocata
    strcpy(this->brand,brand); /// atribuire valoare
    this->model = model;
    this->size = size;
    this->stoc = stoc;
    this->pret = pret;

}
///obiect
Papuci::Papuci(const Papuci& Obj):idProd(contProd++){ ///obiect
    this->brand = new char[strlen(Obj.brand)+1]; ///memorie alocata
    strcpy(this->brand,Obj.brand); /// atribuire valoare
    this->model = Obj.model;
    this->size = Obj.size;
    this->stoc = Obj.stoc;
    this->pret = Obj.pret;
}
class Haine {
private:
    static int contProd;
    const int idProd;
    char *brand; ///{Adidas}
    string model;
    string marime;
    string culoare;
    string material;
    char gen;
    int stoc;
    float pret;
public:
    ///functii
    void afisare();
    void citire();
    ///constructori
    Haine();
    Haine(char *brand, string model,string marime, string culoare, string material, char gen, int stoc, float pret);
    Haine(const Haine& Obj);
    Haine& operator=(const Haine& Obj);
    Haine& operator-(const float &Obj);
    Haine& operator+(const float &Obj);
    Haine& operator*(const float &Obj);
    Haine& operator++();
    Haine operator++(int);
    bool operator ==(const Haine &obj);
    bool operator >(const Haine &obj);
    operator string();
    ///functii friend
    friend ostream& operator <<(ostream& out, const Haine& c1);
    friend istream& operator >>(istream& in,  Haine& obj);
    friend void afisare2(const Haine &Obj);
    friend Haine operator+(int x, Haine &obj);
    friend Haine operator*(int x, Haine &obj);
    ///getteri
    string getBrand(){return this->brand;}
    string getModel(){return this->model;}
    string getMarime(){return this->marime;}
    string getCuloare(){return this->culoare;}
    string getMaterial(){return this->material;}
    char getGen(){return this->gen;}
    int getStoc() {return this->stoc;}
    float getPret(){return this->pret;}
    const int getId(){return this->idProd;}
    ///setteri
    void setBrand(char *x){
        if (this->brand != NULL) {
            delete[] this->brand;
            this->brand = NULL;
        }
        this->brand = new char[strlen(x) + 1];
        strcpy(this->brand, x);
    }
    void setModel(string x){this->model = x;}
    void setMarime(string x){this->marime = x;}
    void setCuloare(string x) {this->culoare = x;}
    void setMaterial(string x){this->material = x;}
    void setGen(char x){ this->gen = x;}
    void setStoc(int x) {this->stoc = x;}
    void setPret(float x){this->pret = x;}
    ///destructor
    ~Haine(){
        if(this -> brand != NULL){
            delete[] this->brand;
            this->brand = NULL;
        }
    }
};

int Haine::contProd=6500;
///supraincarcare operatori

Haine& Haine::operator=(const Haine &Obj) {
    if(this != &Obj) {
        if (this->brand != NULL) {
            delete[] this->brand;
            this->brand = NULL;
        }
        this->brand = new char[strlen(Obj.brand) + 1]; ///memorie alocata
        strcpy(this->brand, Obj.brand); /// atribuire valoare
        this->model = Obj.model;
        this->marime = Obj.marime;
        this->culoare = Obj.culoare;
        this->material = Obj.material;
        this->stoc = Obj.stoc;
        this->pret = Obj.pret;
    }
    return *this;
}
///adunare
Haine& Haine::operator+(const float & Obj){
    this->pret = this->pret + Obj;
    return *this;
}

///float + adunare ???


Haine& Haine::operator-(const float & Obj){
    this->pret = pret - Obj;
    return *this;
}

Haine& Haine::operator*(const float & Obj){
    this->pret = pret * Obj;
    return *this;
}
Haine& Haine::operator++(){
    this->stoc = stoc + 10 ;
    return *this;
}
Haine Haine::operator++(int){
    Haine aux(*this);
    this->stoc = stoc + 10 ;
    return aux;
}
Haine operator+(int x, Haine &obj){
    return obj+x;
}
Haine operator*(int x, Haine &obj){
    return obj*x;
}
bool Haine::operator==(const Haine& obj) {
    return strcmp(this->brand,obj.brand)==0 and this->model.compare(obj.model)==0
           and this->marime.compare(obj.marime)==0 and this->culoare.compare(obj.culoare)==0 and this->material.compare(obj.material)==0 and this->gen==obj.gen and this->stoc==obj.stoc and this->pret==obj.pret;
}
bool Haine::operator>(const Haine& obj){
    return this->pret > obj.pret;
}
Haine::operator string(){
    return this->model;
}

void Haine::afisare(){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Haine: " << this->idProd<<endl;
    cout << "brand: " <<this->brand<<endl;
    cout << "model: " <<this->model<<endl;
    cout << "Marime: "<< this->marime <<endl;
    cout << "Stoc: " << this->stoc <<endl;
    cout << "Pret: " << this->pret <<endl;
}
void afisare2(const Haine& Obj){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Haine: " << Obj.idProd<<endl;
    cout << "brand: " << Obj.brand<<endl;
    cout << "model: " << Obj.model<<endl;
    cout << "Marime: "<< Obj.marime <<endl;
    cout << "Stoc: " << Obj.stoc <<endl;
    cout << "Pret: " << Obj.pret <<endl;
}
/// >> <<
ostream& operator <<(ostream& out, const Haine& c1){
    out<< "Afisare Pereche Papusci : " <<endl;
    out<<"-----------------------------"<<endl;
    out << "id Haine: " << c1.idProd<<endl;
    out << "brand: " <<c1.brand<<endl;
    out << "model: " <<c1.model<<endl;
    out << "Marime: " <<c1.marime<<endl;
    out << "Culoare: "<<c1.culoare<<endl;
    out << "Material: "<<c1.material<<endl;
    out << "Gen: "<<c1.gen<<endl;
    out << "Stoc: " <<c1.stoc<<endl;
    out << "Pret: " <<c1.pret<<endl;
}
istream& operator >>(istream& in,  Haine& obj){
    cout<<"Nume: ";
    char aux[100];
    in >> aux;
    if(obj.brand != NULL){
        delete[] obj.brand;
    }
    obj.brand = new char[strlen(aux)+1];
    strcpy(obj.brand, aux);

    cout << "Model: ";
    in >> obj.model;

    cout << "Marime: ";
    in >> obj.marime;

    cout << "Culoare: ";
    in >> obj.culoare;

    cout<< "Gen : ";
    in >> obj.gen;

    cout << "Material: ";
    in >> obj.material;

    cout << "Stoc: ";
    in >> obj.stoc;

    cout << "Pret: ";
    in >> obj.pret;

}
void Haine::citire(){

    cout << "Afisare informatii relevante: " << endl;

    cout << "Brand: ";
    char aux[100];
    cin >> aux;
    if(this->brand != NULL){
        delete[] this->brand;
    }
    this->brand = new char[strlen(aux)+1];
    strcpy(this->brand, aux);

    cout << "Model: ";
    cin >> this->model;

    cout << "Marime: ";
    cin >> this->marime;

    cout << "Culoare: ";
    cin >> this->culoare;

    cout << "Material: ";
    cin >> this->material;

    cout << "Stoc: ";
    cin >> this->stoc;

    cout << "Pret: ";
    cin >> this->pret;

    cout << endl;
}
///initializare anonim
///initializare_anonim
Haine::Haine():idProd(contProd++){ ///initializare_anonim
    brand = new char[strlen("Anonim")+1];
    strcpy(brand,"Anonim");
    model = "Anonim";
    marime = "Anonim";
    culoare = "Anonim";
    material = "Anonim";
    gen = 'X';
    stoc = 0;
    pret = 0;
}
Haine::Haine(char *brand, string model, string marime, string culoare, string material, char gen, int stoc,
             float pret):idProd(contProd++){
    this->brand = new char[strlen(brand)+1]; ///memorie alocata
    strcpy(this->brand,brand); /// atribuire valoare
    this->model = model; /// TODO ce face std::move(model) ???
    this->marime = marime;
    this->culoare = culoare;
    this->material = material;
    this->gen = gen;
    this->stoc = stoc;
    this->pret = pret;

}
Haine::Haine(const Haine& Obj):idProd(contProd++) {
    this->brand = new char[strlen(brand)+1]; ///memorie alocata
    strcpy(this->brand,brand); /// atribuire valoare
    this->model = model;
    this->marime = marime;
    this->culoare = culoare;
    this->material = material;
    this->gen = gen;
    this->stoc = stoc;
    this->pret = pret;
}
class Comanda {
private:
    static int contorId;
    const int idComanda;
    string localitate;
    bool transport;
    int nrProduse;///{2}
    int* produse; ///{2019,2014} list<int> produse;
    int* cantitate;
    float spret;
public:

    ///cosntructorii
    Comanda();
    Comanda(string localitate,
            bool transport, int nrProduse, int* produse, int* cantitate, float spret);
    Comanda(const Comanda& Obj);
    Comanda& operator=(const Comanda & Obj);

    /// getteri
    int static getContorId();
    int getIdComanda(){return this->idComanda;}
    string getlocalitate(){return this->localitate;}
    const int* getproduse() const {return this->produse;}
    int getnrProduse(){return this->nrProduse;}
    int getPrice(){return this->spret;}

    ///setteri
    int setPrice(float x){ this->spret = x;}
    int setlocalitate(string x){ this->localitate = x; this->transport = true;}

    /// functii
    void afisare();
    void citire();

    /// functii friend
    friend void afisare2(const Comanda& obj);
    friend ostream& operator <<(ostream& out, const Comanda& obj);
    friend istream& operator >>(istream& in, Comanda& obj);

    Comanda& operator ++();
    Comanda operator ++(int);
    Comanda operator +(const Comanda &);
    Comanda operator +(int);
    Comanda operator *(int);
    friend Comanda operator+(int a, Comanda);
    bool operator == (const Comanda &a);
    int operator [] (int);
    operator string();
    operator float()const; ///implicit
    operator float();///explicit
//    friend Comanda operator+(Comanda, int a); i.e linia 45
    ~Comanda(){

        if(this->produse!=NULL)
        {
            delete[] this->produse;
            this->produse=NULL;
        }
        if(this->cantitate!=NULL)
        {
            delete[] this->cantitate;
            this->cantitate=NULL;
        }

    }
};
int Comanda::contorId=5000;
Comanda::operator string(){
    return this->localitate;
}
Comanda::operator float(){
    return this->spret;
}
Comanda::operator float()const{
    return this->spret;
}
int Comanda::operator [] (int a)

{
    if(this->produse == NULL)
        throw runtime_error("Ani votare nu are elemente");
    if(a<0 || a>this->nrProduse)
        throw runtime_error("index invalid");
    else
        return this->produse[a];
}
bool Comanda::operator == (const Comanda &a)
{
    return this->localitate == a.localitate;
}
Comanda operator+(int a, Comanda obj)
{
    return obj+a;
}
Comanda Comanda::operator +(int a)
{
    Comanda aux(*this);
    if (aux.produse != NULL)
        delete [] aux.produse;
    if (aux.cantitate != NULL)
        delete [] aux.cantitate;
    aux.produse = new int[aux.nrProduse + 1];
    aux.cantitate = new int[aux.nrProduse + 1];
    for (int i = 0;  i<this->nrProduse; i++)
    {
        aux.produse[i] = this->produse[i];
        aux.cantitate[i] = this->cantitate[i];
    }
    aux.produse[this->nrProduse] = a;
    aux.cantitate[this->nrProduse] = 1;
    aux.nrProduse++;
    return aux;
}
Comanda Comanda::operator *(int a)
{
    Comanda aux(*this);
    if (aux.produse != NULL)
        delete [] aux.produse;
    if (aux.cantitate != NULL)
        delete [] aux.cantitate;
    aux.produse = new int[aux.nrProduse];
    aux.cantitate = new int[aux.nrProduse];
    for (int i = 0;  i<this->nrProduse-1; i++)
    {
        aux.produse[i] = this->produse[i];
        aux.cantitate[i] = this->cantitate[i];
    }
    aux.produse[this->nrProduse-1] = this->produse[this->nrProduse-1];
    aux.cantitate[this->nrProduse-1] = a;
    return aux;
}
Comanda Comanda::operator +(const Comanda &b)
{
    Comanda aux(*this);
    aux.spret = this->spret+aux.spret;
    aux.localitate = this->localitate + aux.localitate;
    return aux;
}

Comanda& Comanda::operator ++()
{
    this->spret++;
    return *this;
}

Comanda Comanda::operator ++(int)
{
    Comanda aux(*this);
    this->spret++;
    return aux;
}

Comanda& Comanda::operator=(const Comanda& Obj){

    if(this!=&Obj){
        if(this->produse!=NULL)
        {
            delete[] this->produse;
            this->produse=NULL;
        }
        if(this->cantitate!=NULL)
        {
            delete[] this->cantitate;
            this->cantitate=NULL;
        }
        this->localitate=Obj.localitate;
        this->transport=Obj.transport;
        this->nrProduse=Obj.nrProduse;
        this->produse=new int[Obj.nrProduse];
        for(int i=0;i<nrProduse;i++)
            this->produse[i]=Obj.produse[i];
        this->cantitate=new int[Obj.nrProduse];
        for(int i=0;i<nrProduse;i++)
            this->cantitate[i]=Obj.cantitate[i];
        this->spret=Obj.spret;


    }
    return *this;

}
/// tipul Instanta::numele metodei +implemenatrea
int Comanda::getContorId(){return Comanda::contorId;}
Comanda::Comanda():idComanda(contorId++){
    localitate="Anonim";
    transport=false;
    nrProduse=0;
    produse=NULL;
    cantitate = NULL;
    spret=0;
}

Comanda::Comanda(string localitate,
                 bool transport, int nrProduse, int* produse, int* cantitate, float spret) :idComanda(contorId++){


    this->localitate=localitate;
    this->transport=transport;
    this->nrProduse=nrProduse;
    this->produse=new int[nrProduse];
    for(int i=0;i<nrProduse;i++)
        this->produse[i]=produse[i];
    this->cantitate=new int[nrProduse];
    for(int i=0;i<nrProduse;i++)
        this->cantitate[i]=cantitate[i];
    this->spret=spret;
}
Comanda::Comanda(const Comanda& Obj):idComanda(contorId++){
    this->localitate=Obj.localitate;
    this->transport=Obj.transport;
    this->nrProduse=Obj.nrProduse;
    this->produse=new int[Obj.nrProduse];
    for(int i=0;i<nrProduse;i++)
        this->produse[i]=Obj.produse[i];
    this->cantitate=new int[nrProduse];
    for(int i=0;i<nrProduse;i++)
        this->cantitate[i]=cantitate[i];
    this->spret=Obj.spret;}

void Comanda::afisare(){

    cout << "Afisare informatii relevante: " << endl;
    cout << "ID: " << this->idComanda << endl;
    cout << "localitate: " << this->localitate << endl;
    cout << "transport: " << (this->transport ? "Da" : "Nu") << endl;
    cout <<"NR PRODUSE: " <<this<<nrProduse<<'\n';
    cout << "Produse : ";
    for(int i=0; i<this->nrProduse; i++){
        cout << this->produse[i] << " ";
        cout<< this->cantitate[i]<<" ";
        cout<<endl;
    }
    cout << endl;
    cout << "Inaltimea: " << this->spret << " m" << endl;
}

void afisare2(const Comanda& obj){
    cout << "Afisare informatii relevante: " << endl;
    cout << "ID: " << obj.idComanda << endl;
    cout << "localitate: " << obj.localitate << endl;
    cout << "transport: " << (obj.transport ? "Da" : "Nu") << endl;
    cout << "Nr produse: " << obj.nrProduse << endl;

    cout << "Comenzi : ";
    for(int i=0; i<obj.nrProduse; i++){
        cout << obj.produse[i] << " ";
        cout<< obj.cantitate[i]<<" ";
        cout<<endl;
    }
    cout << endl;
    cout << "Pret Total: " << obj.spret << " m" << endl;
}

void Comanda::citire(){

    cout << "Afisare informatii relevante: " << endl;
    cout << "localitate: ";
    cin >> this->localitate;

    cout << "transport: ";
    cin >> this->transport;

    cout << "Nr Produse?";
    cin >> this->nrProduse;

    cout << "Produse :  ";
    if(this->produse != NULL){
        delete[] this->produse;
    }
    if(this->cantitate != NULL){
        delete[] this->cantitate;
    }
    this->produse = new int[this->nrProduse];
    this->cantitate = new int[this->nrProduse];
    for(int i=0; i<this->nrProduse; i++){
        cout<<"Produs : ";
        cin >> this->produse[i];
        cout<<'\n';
        cout<<"Cantitate : ";
        cin >> this->cantitate[i];
        cout<<'\n';
    }

    cout << "Suma Totala: ";
    cin >> this->spret;

    cout << endl;
}

ostream& operator <<(ostream& out, const Comanda& obj){

    out << "Afisare informatii relevante: " << endl;
    out << "ID: " << obj.idComanda << endl;
    out << "localitate: " << obj.localitate << endl;
    out << "transport: " << (obj.transport ? "Da" : "Nu") << endl;
    out << "Nr Produse: ";
    for(int i=0; i<obj.nrProduse; i++){
        out << obj.produse[i] << " ";
        out<< obj.cantitate[i]<<" ";
        out<<endl;
    }
    out << endl;
    out << "Suma Totala: " << obj.spret << " m" << endl;

    return out;
}

istream& operator >>(istream& in, Comanda& obj){


    cout << "localitate: ";
    in >> obj.localitate;

    cout << "transport: ";
    in >> obj.transport;

    cout << "Nr produse? ";
    in >> obj.nrProduse;

    cout << "Produse :  ";
    if(obj.produse != NULL){
        delete[] obj.produse;
    }
    if(obj.cantitate != NULL){
        delete[] obj.cantitate;
    }
    obj.produse = new int[obj.nrProduse];
    for(int i=0; i<obj.nrProduse; i++){
        in >> obj.produse[i];
        in >> obj.cantitate[i];
    }

    cout << "Suma totala: ";
    in >> obj.spret;

    cout << endl;
    return in;
}

class Client{
private:
    static int contorIdC;
    const int idUser;
    string parola;
    char *nume;
    char *prenume;
    int varsta;
    bool premium;
    int nr_comenzi;
    int* comenzi;
    float stotal;
    float puncte;
    ///TODO Comenzi+
public:
    ///construcvtori
    Client();
    Client(char *nume, char *prenume, string parola, int varsta,  bool premium, int nr_comenzi, int* comenzi,float stotal, float puncte);
    Client(const Client& Obj);
    int static getcontorIdC();
    /// operatori
    Client& operator=(const Client & Obj);
    Client& operator++();
    Client operator++(int);
    Client& operator-(const float &Obj);
    Client operator +(int x);
    Client& operator*(const float &Obj);
    Client operator+(Comanda x);
    bool operator ==(const Client &obj);
    bool operator >(const Client &obj);
    int operator [] (int);
    operator string ();
    ///functii friend
    friend ostream& operator <<(ostream& out, const Client& c1);
    friend istream& operator >>(istream& in,  Client& obj);
    friend void afisare2(const Client &Obj);
    friend Client operator+(int x, Client &obj);
    friend Client operator*(int x, Client &obj);
    friend Client operator+(Comanda x, Client &obj);
    const int* getCo() const {return this->comenzi;}

    ///functii
    void afisare();
    void citire();
    ///geteri
    string getNume(){return this->nume;}
    string getPrenume(){return this->prenume;}
    string getParola(){return this->parola;}
    int getVarsta(){return this->varsta;}
    bool getPremium(){return this->premium;}
    int getNrComenzi(){return this->nr_comenzi;}
    float getStotal(){return this->stotal;}
    int getUserId(){return Client::idUser;}
    int getComenzi(int x) const {return this->comenzi[x];}
    ///seterti
    void setnume(char *x){
        if (this->nume != NULL) {
            delete[] this->nume;
            this->nume = NULL;
        }
        this->nume = new char[strlen(x) + 1];
        strcpy(this->nume, x);
    }
    void setComanda(int *x){
        if (this->comenzi != NULL) {
            delete[] this->comenzi;
            this->comenzi = NULL;
        }
        this->nr_comenzi++;
        this->comenzi = new int[nr_comenzi];
    }
    void setparola(string x){this->parola = x;}
    void setvarsta(int x){this->varsta = x;}
    void setSPret(float x){
        this->stotal = x;
        this->puncte += x/66; /// 1.5% cashback
        if(x >=1000)
            this->premium = true;
    }
    ///destructor
    ~Client(){
        if(this->nume!=NULL)
        {
            delete[] this->nume;
            this->nume=NULL;
        }

        if(this->prenume!=NULL)
        {
            delete[] this->prenume;
            this->prenume=NULL;
        }
        if(this->prenume!=NULL)
        {
            delete[] this->comenzi;
            this->comenzi=NULL;
        }

    }
};
int Client::contorIdC=2000;
Client& Client::operator=(const Client& Obj) {

    if (this != &Obj) {
        if (this->nume != NULL) {
            delete[] this->nume;
            this->nume = NULL;
        }

        if (this->prenume != NULL) {
            delete[] this->prenume;
            this->prenume = NULL;
        }
        if(this->comenzi!=NULL)
        {
            delete[] this->comenzi;
            this->comenzi=NULL;
        }
        this->nume = new char[strlen(Obj.nume) + 1];/// doar am alocat memorie
        strcpy(this->nume, Obj.nume);/// atribui valoarea
        this->prenume = new char[strlen(Obj.prenume) + 1];/// doar am alocat memorie
        strcpy(this->prenume, Obj.prenume);/// atribui valoarea
        this->parola = Obj.parola;
        this->varsta = Obj.varsta;
        this->premium = Obj.premium;
        this->nr_comenzi = Obj.nr_comenzi;
        this->comenzi = new int[Obj.nr_comenzi];
        for(int i=0;i<nr_comenzi;i++)
            this->comenzi[i] = Obj.comenzi[i];


        this->stotal = Obj.stotal;
        this->puncte = Obj.puncte;
    }
    return *this;
}
/// << >> afisare citire
void Client::afisare(){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Client: " << this->idUser<<endl;
    cout << "Nume: " <<this->nume<<endl;
    cout << "Prenume: " <<this->prenume<<endl;
    cout << "Parola :" << this->parola<<endl;
    cout << "Varsta: "<< this->varsta <<endl;
    cout << "Cont Premium ? : " << this->premium <<endl;
    cout<< "numar comenzi : "<<this->nr_comenzi<<endl;
    for(int i=0; i<this->nr_comenzi; i++) {
        cout << this->comenzi[i] << " ";
    }
    cout << "Suma totala cheltuita : " << this->stotal <<endl;
    cout << "Puncte Bonus : "<< this->puncte<<endl;
}
void afisare2(const Client& Obj){
    cout<< "Afisare Pereche Papusci : " <<endl;
    cout<<"-----------------------------"<<endl;
    cout << "id Client: " << Obj.idUser<<endl;
    cout << "Nume: " <<Obj.nume<<endl;
    cout << "Prenume: " <<Obj.prenume<<endl;
    cout << "Parola: " <<Obj.parola<<endl;
    cout << "Varsta: "<< Obj.varsta <<endl;
    cout << "Cont Premium ? : " << Obj.premium <<endl;
    cout<< "numar comenzi : "<<Obj.nr_comenzi<<endl;
    for(int i=0; i<Obj.nr_comenzi; i++) {
        cout << Obj.comenzi[i] << " ";
    }
    cout << "Suma totala cheltuita : " << Obj.stotal <<endl;
    cout << "Puncte Bonus : "<< Obj.puncte<<endl;
}
/// >> <<
ostream& operator <<(ostream& out, const Client& c1){
    out<< "Afisare Pereche Papusci : " <<endl;
    out<<"-----------------------------"<<endl;
    out << "id User: " << c1.idUser<<endl;
    out << "Nume: " <<c1.nume<<endl;
    out << "Prenume: " <<c1.prenume<<endl;
    out << "Parola: " <<c1.parola<<endl;
    out << "Varsta: " <<c1.varsta<<endl;
    out << "Cont Premium ?: "<<c1.premium<<endl;
    out<< "numar comenzi : "<<c1.nr_comenzi<<endl;
    for(int i=0; i<c1.nr_comenzi; i++) {
        out << c1.comenzi[i] << " ";
    }
    cout<<'\n';
    out << "Suma totala cheltuita : "<<c1.stotal<<endl;
    out << "Puncte bonus " <<c1.puncte<<endl;
    return out;
}
istream& operator >>(istream& in,  Client& obj){
    cout<<"Nume: ";
    char aux[100];
    in >> aux;
    if(obj.nume != NULL){
        delete[] obj.nume;
    }
    obj.nume = new char[strlen(aux)+1];
    strcpy(obj.nume, aux);

    cout << "Prenume: ";
    in >> aux;
    if(obj.prenume != NULL){
        delete[] obj.prenume;
    }
    obj.prenume = new char[strlen(aux)+1];
    strcpy(obj.prenume, aux);

    cout << "Parola: ";
    in >> obj.parola;

    cout << "Varsta: ";
    in >> obj.varsta;
    cout<<endl;
    cout<<"ID TAU PENTRU LOGARE : ";
    cout<<obj.idUser;
/**
    cout << "Cont Premium: ";
    in >> obj.premium;

    cout << "Nr comenzi efectuate? ";
    cin >> obj.nr_comenzi;

    cout << "Comenzi : ? ";
    if(obj.comenzi != NULL){
        delete[] obj.comenzi;
    }
    obj.comenzi = new int [obj.nr_comenzi];
    for(int i=0; i<obj.nr_comenzi; i++){
        cout<<"comanda cu nr : ";
        in >> obj.comenzi[i];
    }

    cout << "Pret total: ";
    in >> obj.stotal;

    cout << "Puncte bonus: ";
    in >> obj.stotal;
    return in;
*/
}
void Client::citire(){

    cout << "Afisare informatii relevante: " << endl;

    cout<<"Nume: ";
    char aux[100];
    cin >> aux;
    if(this-> nume != NULL){
        delete[] this-> nume;
    }
    this-> nume = new char[strlen(aux)+1];
    strcpy(this-> nume, aux);

    cout << "Prenume: ";
    cin >> aux;
    if(this->prenume != NULL){
        delete[] this-> prenume;
    }
    this->prenume = new char[strlen(aux)+1];
    strcpy(this-> prenume, aux);

    cout << "Parola: ";
    cin >> this-> parola;

    cout << "Varsta: ";
    cin >> this-> varsta;

    cout << "Cont Premium: ";
    cin >> this-> premium;

    cout << "Nr comenzi efectuate? ";
    cin >> this->nr_comenzi;

    cout << "Comnzi :  \n";
    if(this->comenzi != NULL){
        delete[] this->comenzi;
    }
    this->comenzi = new int[this->nr_comenzi];
    for(int i=0; i<this->nr_comenzi; i++){
        cout<<"comanda cu nr : ";
        cin >> this->comenzi[i];
    }

    cout << "Pret total: ";
    cin >> this-> stotal;

    cout << "Puncte bonus: ";
    cin >> this-> stotal;
}
///adunare


///float + adunare ???


Client& Client::operator-(const float & Obj){
    this->puncte = puncte - Obj;
    return *this;
}

Client& Client::operator*(const float & Obj){
    this->puncte = puncte * Obj;
    return *this;
}
Client& Client::operator++(){
    this->varsta = varsta + 1 ;
    return *this;
}
Client Client::operator++(int){
    Client aux(*this);
    operator++();
    return aux;
}
Client Client::operator+(int x) {
    Client aux(*this);
    if(aux.comenzi != NULL)
    {   ///cout<<"Daaaa\n";
        delete [] aux.comenzi;}
    aux.comenzi = new int[aux.nr_comenzi + 1];
    for(int i=0;i<this->nr_comenzi;i++){
        aux.comenzi[i]=this->comenzi[i];
    }
    aux.comenzi[this->nr_comenzi] = x;
    aux.nr_comenzi++;
    return aux;
}
Client operator*(int x, Client &obj){
    return obj*x;
}
Client operator+(int x, Client &obj){
    return obj+x;
}
Client Client::operator+(Comanda x) {
    Client aux(*this);
    if(aux.comenzi != NULL)
    {   ///cout<<"Daaaa\n";
        delete [] aux.comenzi;}
    aux.comenzi = new int[aux.nr_comenzi + 1];
    for(int i=0;i<this->nr_comenzi;i++){
        aux.comenzi[i]=this->comenzi[i];
    }
    aux.comenzi[this->nr_comenzi] = x.getIdComanda();
    aux.nr_comenzi++;
    return aux;
}
Client operator+(Comanda x, Client &obj){
    return obj+x;
}

bool Client::operator==(const Client& obj) {
    if(strcmp(this->nume,obj.nume)==0 and strcmp(this->prenume,obj.prenume)==0 and this->varsta==obj.varsta and this->premium==obj.premium and this->nr_comenzi==obj.nr_comenzi){
        for(int i=0;i<obj.nr_comenzi;i++){
            if(this->comenzi[i]!=obj.comenzi[i])
                return 0;
        }
        return 1;
    }
    return 0;
}
bool Client::operator>(const Client& obj){
    return this->stotal > obj.stotal;
}
int Client::operator [] (int a){
    if(this->nr_comenzi == 0)
        throw runtime_error("Ani votare nu are elemente");
    if(a<0 || a>this->nr_comenzi)
        throw runtime_error("index invalid");
    else
        return this->comenzi[a];
}
Client::operator string() {
    return this->parola;
}
int Client::getcontorIdC(){return Client::contorIdC;}
Client::Client():idUser(contorIdC++){
    nume = new char[strlen("ANONIM")+1];
    strcpy(nume,"Anonim");/// atribui valoarea
    prenume = new char[strlen("ANONIM")+1];
    strcpy(prenume,"Anonim");/// atribui valoarea
    parola = "****";
    varsta= 0;
    premium = false;
    nr_comenzi=0;
    comenzi=NULL;
    stotal = 0;
    puncte = 0;
}
Client::Client(char *nume, char *prenume, string parola, int varsta, bool premium, int nr_comenzi, int *comenzi  ,float stotal, float puncte):idUser(contorIdC++) {
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->prenume=new char[strlen(nume)+1];
    strcpy(this->prenume,nume);
    this->parola = parola;
    this->varsta = varsta;
    this->premium = premium;
    this->nr_comenzi = nr_comenzi;
    this->comenzi = new int[nr_comenzi];
    for(int i=0;i<nr_comenzi;i++)
        this->comenzi[i] = comenzi[i];
    this->stotal = stotal;
    this->puncte = puncte;
}
Client::Client(const Client &Obj):idUser(contorIdC++) {
    this->nume=new char[strlen(Obj.nume)+1];
    strcpy(this->nume,Obj.nume);
    this->prenume=new char[strlen(Obj.nume)+1];
    strcpy(this->prenume,Obj.nume);
    this->parola = Obj.parola;
    this->varsta = Obj.varsta;
    this->premium = Obj.premium;
    this->nr_comenzi = Obj.nr_comenzi;
    this->comenzi = new int[Obj.nr_comenzi];
    for(int i=0;i<nr_comenzi;i++)
        this->comenzi[i] = Obj.comenzi[i];
    this->stotal = Obj.stotal;
    this->puncte = Obj.puncte;
}


int main() {
    cout << "Bine ati venit !!!" << endl;
    Papuci listaPapuci[1000];
    int contPapuci = 0;
    Haine listaHaine[1000];
    int contHaine = 0;
    Client listaClienti[1000];
    int contClienti = 0;
    Comanda listaComenzi[10000];
    int contComenzi = 0;

    bool k = true;
    int key = 1111;
    while (k) {
        int com;
        cout << "\n1-Admin;";
        cout << "\n2-Utilizator;";
        cout << "\n3-STOP";
        cout << endl;
        cout << "alageti comanda : ";
        cin >> com;
        system("CLS");
        switch (com) {
            case 1: { ///admin
                cout << "Password : ";
                int password;
                cin >> password;
                system("CLS");
                /// system("CLS");
                if (password==key){
                    bool okadmin = true;
                    while (okadmin) {
                        cout << "Comenzi Admin : ";
                        cout << "\n1-Adaugati Papuci;";
                        cout << "\n2-Vizualizati Papuci; ";
                        cout << "\n3-Adaugati Haine;";
                        cout << "\n4-Vizualizati Haine; ";
                        cout << "\n5-Iesire\n ";
                        int comadmin;
                        cout << "alageti comanda : ";
                        cin >> comadmin;
                        system("CLS");
                        switch (comadmin) {
                            case 1: {
                                Papuci A;
                                cin >> A;
                                system("CLS");
                                listaPapuci[contPapuci++] = A;
                                break;
                            }
                            case 2: {
                                /// system("CLS");
                                cout<<"Afiasre Produs\n-----------------\n";
                                bool kpapuci = true;
                                int cursor = 0;
                                while (kpapuci) {
                                    cout << listaPapuci[cursor];
                                    cout << endl;
                                    int comanda_papuci;
                                    cout << "Comenzi Papuci ` : ";
                                    cout << "\n1-Inainte;";
                                    cout << "\n2-Inapoi;";
                                    cout << "\n3-Modificati;";
                                    cout << "\n4-Iesire; \n";
                                    cout << "Introduceti comanda : ";
                                    cin >> comanda_papuci;
                                    system("CLS");
                                    switch (comanda_papuci) {
                                        case 1: {
                                            cursor++;
                                            break;
                                        }
                                        case 2: {
                                            cursor--;
                                            break;
                                        }
                                        case 3: {
                                            int loopPapuci = true;
                                            while (loopPapuci == true) {
                                                cout << "MODIFICARI PAPUCI\n";
                                                cout << "\n1-Brand;";
                                                cout << "\n2-Model;";
                                                cout << "\n3-Marime;";
                                                cout << "\n4-Stoc;";
                                                cout << "\n5-Pret";
                                                cout << "\n6-Iesire";
                                                cout <<"\n----------------------------";
                                                cout << "\nAlegeti comanda: ";
                                                int modPapuci;
                                                cin >> modPapuci;
                                                system("CLS");
                                                switch (modPapuci) {
                                                    case 1: {///brand
                                                        cout << "nume Brand : ";
                                                        char y[50];
                                                        cin >> y;
                                                        listaPapuci[cursor].setBrand(y);
                                                        break;
                                                    }
                                                    case 2: {///model
                                                        cout << "nume Model : ";
                                                        char y[50];
                                                        cin >> y;
                                                        system("CLS");
                                                        listaPapuci[cursor].setModel(y);
                                                        break;
                                                    }
                                                    case 3: {///marime
                                                        cout << "Marime : ";
                                                        int y;
                                                        cin >> y;
                                                        system("CLS");
                                                        listaPapuci[cursor].setSize(y);
                                                        break;
                                                    }
                                                    case 4: {///stoc
                                                        cout << "Stoc Nou : ";
                                                        int y;
                                                        cin >> y;
                                                        system("CLS");
                                                        listaPapuci[cursor].setStoc(y);
                                                        break;
                                                    }
                                                    case 5: {///pret
                                                        int comanda_pret;
                                                        cout<<"\nMARIRE PRET \n";
                                                        cout << "\n1-Marire procent;";
                                                        cout << "\n2-Marire fixa;";
                                                        cout<< "\nComanda : ";
                                                        cin>>comanda_pret;
                                                        system("CLS");

                                                        if (comanda_pret==1) {
                                                            float procent;
                                                            cin>>procent;
                                                            procent = procent/100+1;
                                                            listaPapuci[cursor] = listaPapuci[cursor]*procent;
                                                            break;
                                                        }
                                                        if(comanda_pret==2){
                                                            float total;
                                                            cin>>total;
                                                            listaPapuci[cursor] = listaPapuci[cursor]+total;
                                                            break;
                                                        }
                                                    }
                                                    case 6: {///iesire
                                                        loopPapuci = false;
                                                        break;
                                                    }

                                                }
                                            }
                                            break;
                                        }
                                        case 4: { ///out
                                            kpapuci = false;
                                            break;
                                        }

                                    }
                                }
                                break;
                            }
                            case 3: {
                                Haine B;
                                cin >> B;
                                system("CLS");
                                listaHaine[contHaine++] = B;
                                break;
                            }
                            case 4: {
                                bool khaine = true;
                                int cursor = 0;
                                system("CLS");
                                cout<<"Afiasre Produs\n-----------------\n";
                                while (khaine) {
                                    cout << listaHaine[cursor];
                                    cout << endl;
                                    int comanda_haine;
                                    cout << "Comenzi Haine : ";
                                    cout << "\n1-Inainte;";
                                    cout << "\n2-Inapoi;";
                                    cout << "\n3-Modificati;";
                                    cout << "\n4-Iesire; \n";
                                    cout << "Introduceti comanda : ";
                                    cin >> comanda_haine;
                                    system("CLS");
                                    switch (comanda_haine) {
                                        case 1: {
                                            cursor++;
                                            break;
                                        }
                                        case 2: {
                                            cursor--;
                                            break;
                                        }
                                        case 3: {
                                            int loopHaine = true;
                                            while (loopHaine == true) {
                                                cout << "MODIFICARI Haine\n";
                                                cout << "\n1-Brand;";
                                                cout << "\n2-Model;";
                                                cout << "\n3-Marime;";
                                                cout << "\n4-Culoare;";
                                                cout << "\n5-Material;";
                                                cout << "\n6-Gen;";
                                                cout << "\n7-Stoc;";
                                                cout << "\n8-Pret";
                                                cout << "\n9-Iesire\n";
                                                cout <<"\n----------------------------";
                                                cout << "Alegeti comanda: ";
                                                int modHaine;
                                                cin >> modHaine;
                                                system("CLS");
                                                switch (modHaine) {
                                                    case 1: {///brand
                                                        cout << "nume Brand : ";
                                                        char y[50];
                                                        cin >> y;
                                                        listaHaine[cursor].setBrand(y);
                                                        break;
                                                    }
                                                    case 2: {///model
                                                        cout << "nume Model : ";
                                                        char y[50];
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setModel(y);
                                                        break;
                                                    }
                                                    case 3: {///marime
                                                        cout << "Marime : ";
                                                        char y[3];
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setMarime(y);
                                                        break;
                                                    }
                                                    case 4: {///culoare
                                                        cout << "Culoare : ";
                                                        char y[20];
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setCuloare(y);
                                                        break;
                                                    }
                                                    case 5: {///material
                                                        cout << "Material : ";
                                                        char y[10];
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setMaterial(y);
                                                        break;
                                                    }
                                                    case 6: {///gen
                                                        cout << "Gen : ";
                                                        char y;
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setGen(y);
                                                        break;
                                                    }
                                                    case 7: {///stoc
                                                        cout << "Stoc Nou : ";
                                                        int y;
                                                        cin >> y;
                                                        system("CLS");
                                                        listaHaine[cursor].setStoc(y);
                                                        break;
                                                    }
                                                    case 8: {///pret
                                                        int comanda_pret;
                                                        cout<<"\nMARIRE PRET \n";
                                                        cout << "\n1-Marire procent;";
                                                        cout << "\n2-Marire fixa;";
                                                        cout<< "\nComanda : ";
                                                        cin>>comanda_pret;
                                                        system("CLS");
                                                        if (comanda_pret==1) {
                                                            float procent;
                                                            cin>>procent;
                                                            procent = procent/100+1;
                                                            listaHaine[cursor] = listaHaine[cursor]*procent;
                                                            break;
                                                        }
                                                        if(comanda_pret==2){
                                                            float total;
                                                            cin>>total;
                                                            listaHaine[cursor] = listaHaine[cursor]+total;
                                                            break;
                                                        }
                                                        break;
                                                    }
                                                    case 9: {///iesire
                                                        loopHaine = false;
                                                        break;
                                                    }

                                                }
                                            }
                                            break;
                                        }
                                        case 4: {
                                            khaine = false;
                                            break;
                                        }

                                    }
                                }
                                break;
                            }
                            case 5: {
                                okadmin = false;
                                break;
                            }
                        }
                    }
                }
                else {
                    cout << "Password wrong : ";
                }
                break;
            }
            cout<<com;
            case 2:{
            bool cuser = true;
            while(cuser){
                int menu_user;
                cout<<"\nProfil Utilizator\n";
                cout<<"++++++++++++++++++++++++";
                cout<< "\n1-Creere cont;";
                cout<< "\n2-Log in: ";
                cout<< "\n3-Iesire";
                cout<<"\nintroduceti comanda: ";
                cin>>menu_user;
                switch (menu_user) {
                    case 1:{
                        cin >> listaClienti[contClienti++];
                        break;
                    }
                    case 2:{
                        ///system("CLS");
                        int id_user;
                        string password;
                        cout<<"\nCod Utilizator : ";
                        cin>>id_user;
                        cout<<"\nParola : ";
                        cin>>password;
                        int locClient = 0;
                        bool ok= false;
                        for(int i=0;i<=contClienti and ok == false;i++){
                            if(listaClienti[i].getUserId() == id_user) {
                                if (listaClienti[i].getParola().compare(password) == 0) {
                                    ok = true;
                                    locClient = i;
                                }
                            }
                        }
                        system("CLS");
                        if(ok==true){
                            cout<<"\nBine ati venit !!!\n-----------------\n";
                            cout<<"Comenzi : \n";
                            cout<<"\n1-Comanda Noua";
                            cout<<"\n2-Vezi comenzi efectuate";
                            cout<<"\n3-Modificare Parola";
                            cout<<"\n4-Iesire";
                            cout<<"\n comanda :";
                            int comanda_user;
                            int index_comanda;
                            cin>>comanda_user;
                            system("CLS");
                            switch (comanda_user) {
                                case 1:{
                                bool ok_comanda = true;
                                Comanda D;
                                while(ok_comanda){
                                    cout << "\n1-Papuci;";
                                    cout << "\n2-Haine;";
                                    cout << "\n3-Confirmare";
                                    cout << "\n4-Iesire; \n";
                                    cout<< "comanda 1/2/3/4: ";
                                    int cbuy = 0;
                                    cin>>cbuy;
                                    system("CLS");
                                    switch (cbuy) {
                                        case 1:{
                                            bool BuyPapuci = true;
                                            int cursor = 0;
                                            while(BuyPapuci){
                                                cout<<listaPapuci[cursor];
                                                cout << "Comenzi Papuci ` : ";
                                                cout << "\n1-Inapoi;";
                                                cout << "\n2-Inainte;";
                                                cout << "\n3-Adauga in cos;";
                                                cout << "\n4-Iesire; \n---------------\n";
                                                cout<<"Comanda : ";
                                                int comanda_papuci;
                                                cin>>comanda_papuci;
                                                system("CLS");
                                                switch (comanda_papuci) {
                                                    case 1:{
                                                        cursor--;
                                                        break;
                                                    }
                                                    case 2:{
                                                        cursor++;
                                                        break;
                                                    }
                                                    case 3:{
                                                        cout<<"\nNr Bucati :";
                                                        int y;
                                                        cin>>y;
                                                        system("CLS");
                                                        if(listaPapuci[cursor].getStoc()>= y){
                                                            int stoc_nou = listaPapuci[cursor].getStoc() - y;
                                                            listaPapuci[cursor].setStoc(stoc_nou);
                                                            ///adaugare produs
                                                            listaComenzi[contComenzi] = listaComenzi[contComenzi] + listaPapuci[cursor].getIdPapuci();
                                                            listaComenzi[contComenzi] = listaComenzi[contComenzi] * y;
                                                            index_comanda = contComenzi;

                                                            float s = y * listaPapuci[cursor].getPret();
                                                            s = s + listaComenzi[index_comanda].getPrice();
                                                            listaComenzi[contComenzi].setPrice(s);
                                                        }
                                                        else{
                                                            cout<<"\n****************\nSTOC INDISPONIBIL\n****************\n";
                                                        }
                                                        break;
                                                    }
                                                    case 4:{
                                                        BuyPapuci = false;
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        case 2:{
                                            bool BuyHaine = true;
                                            int cursor = 0;
                                            while(BuyHaine){
                                                cout<<listaHaine[cursor];
                                                cout << "Comenzi Haine ` : ";
                                                cout << "\n1-Inapoi;";
                                                cout << "\n2-Inainte;";
                                                cout << "\n3-Adauga in cos;";
                                                cout << "\n4-Iesire; \n---------------\n";
                                                cout<<"Comanda : ";
                                                int comanda_haine;
                                                cin>>comanda_haine;
                                                system("CLS");
                                                switch (comanda_haine) {
                                                    case 1:{
                                                        cursor--;
                                                        break;
                                                    }
                                                    case 2:{
                                                        cursor++;
                                                        break;
                                                    }
                                                    case 3:{
                                                        cout<<"\nNr Bucati :";
                                                        int y;
                                                        cin>>y;
                                                        system("CLS");
                                                        if(listaHaine[cursor].getStoc()>= y){
                                                            int stoc_nou = listaHaine[cursor].getStoc() - y;
                                                            listaHaine[cursor].setStoc(stoc_nou);
                                                            ///adaugare produs;
                                                            listaComenzi[contComenzi] = listaComenzi[contComenzi] + listaHaine[cursor].getId();
                                                            listaComenzi[contComenzi] = listaComenzi[contComenzi] * y;
                                                            index_comanda = contComenzi;

                                                            float s = y * listaHaine[cursor].getPret();
                                                            s = s + listaComenzi[index_comanda].getPrice();
                                                            listaComenzi[contComenzi].setPrice(s);
                                                        }
                                                        else{
                                                            cout<<"\n****************\nSTOC INDISPONIBIL\n****************\n";
                                                        }
                                                        break;
                                                    }
                                                    case 4:{
                                                        BuyHaine = false;
                                                        break;
                                                    }

                                                }
                                            }
                                            break;
                                        }
                                        case 3:{
                                            int tr;
                                            cout<<"\nDoriti Transport ? 1-da//0-nu ";
                                            cin>>tr;
                                            if(tr==1) {
                                                string yy;
                                                cout << "\nLocalitate : ";
                                                cin >> yy;
                                                listaComenzi[contComenzi].setlocalitate(yy);
                                            }
                                            system("CLS");
                                            cout<<"\n**********\nComanda a fost inregistrata\n*************\n";
                                            int y =listaComenzi[index_comanda].getIdComanda();
                                            listaClienti[locClient] = listaClienti[locClient] + y;
                                            float s;
                                            s = listaComenzi[index_comanda].getPrice();
                                            s = s + listaClienti[locClient].getStotal();
                                            listaClienti[locClient].setSPret(s);
                                            cout<<listaClienti[locClient];
                                            contComenzi++;
                                            break;

                                        }
                                        case 4:{
                                            ok_comanda = false;
                                            break;
                                        }
                                    }
                                }
                                break;
                                }
                                case 2:{
                                    int k = listaClienti[locClient].getNrComenzi();
                                    for(int i=0;i<k;i++) {
                                            cout<<k;
                                            int y = listaClienti[locClient].getComenzi(i);
                                            for (int j = 0; j <= index_comanda; j++) {
                                                if (listaComenzi[j].getIdComanda() == y) {
                                                    cout << "\nURMATOAREA COMANDA\n";
                                                    cout << listaComenzi[j];
                                               }
                                            }
                                    }
                                    break;
                                }
                            case 3:{
                                cout<<"\n Schimbare Parola\n-------------";
                                cout<<"\nParola Noua : ";
                                string parola;
                                cin>>parola;
                                system("CLS");
                                for(int i=0;i<contClienti;i++)
                                    if(listaClienti[i].getUserId() == id_user)
                                        listaClienti[i].setparola(parola);
                                break;
                                }
                            }
                        }

                        else{
                            cout<<"Codul de utiliztor sau parola este gresita;";
                        }
                        break;
                    }
                    case 3:{
                        cuser = false;
                        break;

                    }
                }
            }
           break;
        }
            case 3: {
                cout << "Multumim";
                k = false;
                break;
            }
        }
    }
}
/**
        Papuci B;
        Client H;
        Client G;
        Comanda L;
        Comanda N;
        L=N;
        cout<<L;
        ///L = L + B;
        cout<<L;
        if(H==G)
            cout<<"DA  ";
        char b[] = {"Adidas"};
        Papuci B2(b, "Ultraboost 3.0", 43, 100, 850);
        B2 = B2 + 6;
        Papuci B3(B2), B4 = B2;
        B4.afisare();
        B4++;
        B4.afisare();
    }
    /**
    Client R;
    char n[] = {"Lovric"};
    char p[] = {"Radu"};
    Client R2(n,p, 18, false, 0);
    cout<<R2.getcontorIdC()<<'\n';
    Client R3(R2), R4=R2;
    cout<<R4.getcontorIdC()<<'\n';
    R4=R;
    cout<<R2.getUserId();

    Comanda F;
    Comanda F2();



    return 0;
}
     **/