#ifndef ConversorRomanos_h 
#define ConversorRomanos_h

#include <string>
#include <map>

using namespace std;


//! Classe de convercao
/*!
	Classe responsavel por converter algarismos romanos para valores decimais
*/

class ConversorRomanos
{
	private:
	
	public:
		
		//!Mapa utilizado para guardar algarismos validos e seus valores em decimais 
		/*
		*/
		static map<char,int> valAlg;
		
		//!Tamanho maximo permitido para validacao 
		/*!
		*/
		const static int MAXSIZE;
		
		//! Avalia se tamanho do parametro algarismos nao e 0 nem maior que 30 caracteres
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Validar_Tamanho(string algarismos);
		
		//! Procura por caracteres invalidos diferentes de  i,v,x,l,c,d,m
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Validar_Caracteres(string algarismos);
		
		//! Avalia quantidade repetida de caracteres validos ou nao
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Validar_Quant_Algarismos_Iguais(string algarismos);
		
		//! Avalia formato da string em algarismos romanos
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Validar_Ordem_Algarismos(string algarismos);
		
		//! Faz o calculo da string seja esta valida ou nao
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Calcular_Decimal(string algarismos);
		
		//! Compila funcoes da classe para retornar um valor caso string seja valida
		/*!
		  \param algarismos string a ser avaliada.
		  \return resultado 0 ou 1 da avaliacao.
		*/
		int Converter_Romano_Decimal(string algarismos);

};
#endif
