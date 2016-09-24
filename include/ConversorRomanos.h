#ifndef ConversorRomanos_h 
#define ConversorRomanos_h

#include <string>
#include <map>

using namespace std;

class ConversorRomanos
{
	private:
	
	public:
		
		static map<char,int> valAlg;
		
		const static int MAXSIZE;
				
		int Validar_Tamanho(string algarismos);
		int Validar_Caracteres(string algarismos);
		int Validar_Quant_Algarismos_Iguais(string algarismos);
		int Validar_Ordem_Algarismos(string algarismos);
		int Calcular_Decimal(string algarismos);
		int Converter_Romano_Decimal(string algarismos);

};
#endif
