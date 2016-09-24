#include "ConversorRomanos.h"
#include <iostream> 
#include <map>
#include <string>

using namespace std;

const int ConversorRomanos::MAXSIZE = 30;
map<char,int> ConversorRomanos::valAlg = 
{{'i',1},{'v',5},{'x',10},{'l',50},{'c',100},{'d',500},{'m',1000},
 {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};


int ConversorRomanos::Validar_Tamanho(string algarismos)
{
	if(algarismos.size() > MAXSIZE || algarismos.empty())
		return 0;//tamanhos nao permitidos x = 0 e x > 30
	else
		return 1;
}

//para que seja convertido sera necessario que o tamanho, a quantidade e a
//validade dos caracteres ja tenham sido avaliados, ou seja tamanho nao sera
//nulo e havera pelo menos um caracter e caso hajam mais estes tambem serao validos
int ConversorRomanos::Validar_Ordem_Algarismos(string algarismos)
{
	for(unsigned int i = 0; i<algarismos.size(); i++)
	{
		for(unsigned int j = i + 1; j<algarismos.size(); j++)
		{
			if(valAlg[algarismos[i]] == valAlg['I'])//----------------- OK
			{
				//a direita de I nao temos L,C,D nem M 
				if(valAlg[algarismos[j]] >= valAlg['L'])
					return 0;
				
				//caso tenhamos a direita de I um valor maior que I e possivel
				//no caso X ou V, somente poderemos ter valores menores que I
				//a direita de X ou V 
				if(valAlg[algarismos[j]] == valAlg['X'] || 
				valAlg[algarismos[j]] == valAlg['V'])
				{
					//alem disso a esquerda nao poderemos ter mais que um valor
					//de I por exemplo caso ocorra IIX
					for(unsigned int k = 0; k < j - 1; k++)
						if(valAlg[algarismos[k]] == valAlg['I'])
							return 0;
				
					//neste caso nenhum valor sera aceito uma vez que nao existem
					//algarismos menores do que I
					for(unsigned int k = j + 1; k < algarismos.size(); k ++)
							return 0;	
				}
			}
			else if(valAlg[algarismos[i]] == valAlg['V'])//------------- OK
			{
				//a direita de V temos apenas I
				if(valAlg[algarismos[j]] != valAlg['I'])
					return 0;
			}
			else if(valAlg[algarismos[i]] == valAlg['X'])//------------ OK
			{
				//a direita de X nao temos D nem M 
				if(valAlg[algarismos[j]] >= valAlg['D'])
					return 0;
					
				//caso tenhamos a direita de X valores L ou C, somente poderemos
				//ter valores menores do que X a direita de L e C
				if(valAlg[algarismos[j]] == valAlg['L'] || 
				valAlg[algarismos[j]] == valAlg['C'])
				{
					//alem disso a esquerda nao poderemos ter mais que um valor
					//de X por exemplo caso ocorra XXC
					for(unsigned int k = 0; k < j - 1; k++)
						if(valAlg[algarismos[k]] == valAlg['X'])
							return 0;
				
					for(unsigned int k = j + 1; k < algarismos.size(); k ++)
						if(valAlg[algarismos[k]] >= valAlg['X'])
							return 0;	
				}
			}
			else if(valAlg[algarismos[i]] == valAlg['L'])//----------- OK
			{
				//a direita de L nao temos L,C,D nem M 
				if(valAlg[algarismos[j]] >= valAlg['L'])
					return 0;
			}
			else if(valAlg[algarismos[i]] == valAlg['C'])//----------- OK
			{
				//caso tenhamos a direita de C valores D ou M, somente poderemos
				//ter valores menores do que C a direita de D e M
				if(valAlg[algarismos[j]] == valAlg['D'] || 
			    valAlg[algarismos[j]] == valAlg['M'])
			    {
			    	//alem disso a esquerda nao poderemos ter mais que um valor
					//de C por exemplo caso ocorra CCM
					for(unsigned int k = 0; k < j - 1; k++)
						if(valAlg[algarismos[k]] == valAlg['C'])
							return 0;
			    
					for(unsigned int k = j + 1; k < algarismos.size(); k ++)
						if(valAlg[algarismos[k]] >= valAlg['C'])
							return 0;	
				}
			}
			else if(valAlg[algarismos[i]] == valAlg['D'])//----------- OK
			{
				//a direita de D nao temos D nem M 
				if(valAlg[algarismos[j]] >= valAlg['D'])
					return 0;
			}
			else if(valAlg[algarismos[i]] == valAlg['M'])//----------- OK
			{
				//Todos os outros casos irao levar M em consideracao para avaliacao
				continue;
			}
		}
	}

	return 1;
}

//quantidade maxima de 3 caracteres iguais
int ConversorRomanos::Validar_Quant_Algarismos_Iguais(string algarismos)
{
	if(!Validar_Tamanho(algarismos))
		return 0;	

	char algAtual;
		
	while(!algarismos.empty())
	{
		int quant = 0;
		bool erased = false;
		algAtual = algarismos[0];
		
		for(unsigned int i = 0; i < algarismos.size(); erased ? i : i++)
		{
			erased =false;
			if(algarismos[i] == algAtual)
			{
				erased = true;
				quant++;
				algarismos.erase(i,1);
			}
		}
		
		if(quant > 3)
			return 0;
		
	}

	return 1;
}

//validos apenas i,v,x,l,c,d,m maisculos e minusculos
int ConversorRomanos::Validar_Caracteres(string algarismos)
{
	if(!Validar_Tamanho(algarismos))
		return 0;

	for(unsigned int i = 0; i < algarismos.size(); i++)
		if(valAlg[algarismos[i]] == 0)
			return 0;//map retorna valor 0 para caracteres nao inclusos
			
	return 1;//caso nao tenha dado erro 
}

//deve receber string correta porem caso receba string incorreta nao havera nenhum erro
//fatal porem valor nao tera significado algum  
int ConversorRomanos::Calcular_Decimal(string algarismos)
{
	if(!Validar_Tamanho(algarismos))
		return 0;

	char algAnt;
	char algAtual = algarismos[algarismos.size() - 1];
	int valor = 0;
	
	for(int i = algarismos.size() - 1; i >= 0; i--)
	{
		algAnt = algAtual;
		algAtual = algarismos[i];	
	
		if(valAlg[algAtual] >= valAlg[algAnt])
			valor += valAlg[algAtual];
		else
			valor -= valAlg[algAtual];
				
	}

	return valor;
}

int ConversorRomanos::Converter_Romano_Decimal(string algarismos)
{
	if(!Validar_Tamanho(algarismos))
		return 0;
		
	//cout << "Tamanho Correto" << endl;
	
	if(!Validar_Caracteres(algarismos))
		return 0;
		
	//cout << "Caracteres Validos" << endl;
	
	if(!Validar_Quant_Algarismos_Iguais(algarismos))
		return 0;
		
	//cout << "Quantidades validas" << endl;
	
	if(!Validar_Ordem_Algarismos(algarismos))
		return 0;
	
	//cout << "Formato valido" << endl;
	
	return Calcular_Decimal(algarismos);
}















