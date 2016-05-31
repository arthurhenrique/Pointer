#include <iostream> 

using namespace std; 

//copia(int, const char*, int)
//Depurar programa
//Imprime [__LINE__] __FUNCTION__(value);
void debug(int value, const char *function, int line)
{
    cout << "[" << line << "] " << function << "("<< value <<");" <<  endl;
}
//copia(int)
//Recebe valor e altera localmente
void copia(int value)
{
    debug(value,__FUNCTION__, __LINE__);
    value = 0;
    debug(value,__FUNCTION__, __LINE__);
}
//copiaPonteiro(int*)
//Recebe valor e altera globalmente através de ponteiro
void copiaPonteiro(int *value)
{
    debug(*value,__FUNCTION__, __LINE__);
    *value = 0;
    debug(*value,__FUNCTION__, __LINE__);
}
//referencia(int &endereço)
//Recebe valor e altera globalmente através de endereço
void referencia(int &value)
{
    debug(value,__FUNCTION__, __LINE__);
    value = 0;
    debug(value,__FUNCTION__, __LINE__);
}

int main(int argc, const char *argv[])
{
    int x = 100;
    int y = 100;
    int z = 100;

    //Passagem por copia - variavel local
    debug(x,__FUNCTION__, __LINE__);
    copia(x);
    debug(x,__FUNCTION__, __LINE__);
    cout << endl;

    //Passagem por referência, enviado endereço &x - variavel global
    debug(y,__FUNCTION__, __LINE__);
    copiaPonteiro(&y);
    debug(y,__FUNCTION__, __LINE__);
    cout << endl;

    //Passagem por referência - variavel global
    debug(z,__FUNCTION__, __LINE__);
    referencia(z);
    debug(z,__FUNCTION__, __LINE__);
    cout << endl;

    return 0;

}