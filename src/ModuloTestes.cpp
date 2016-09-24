#include "ConversorRomanos.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

TEST(ConversorRomanos, ConverterDecimal)
{
	cout<<endl;
	
	ConversorRomanos test;
	string test0 = "MMCMXXXVIII";
	string test1 = "CDXLIII";
	string test2 = "XIXI";
	
	EXPECT_EQ(2938,test.Converter_Romano_Decimal(test0));
	EXPECT_EQ(443,test.Converter_Romano_Decimal(test1));
	EXPECT_EQ(0,test.Converter_Romano_Decimal(test2));

	cout<<endl;
}


TEST(ConversorRomanos, FormatoValido)
{
	cout<<endl;
	
	ConversorRomanos test;
	string test0 = "MMCMXXXVIII";
	string test1 = "XIXI";
	
	EXPECT_EQ(1,test.Validar_Ordem_Algarismos(test0));
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(test1));

	cout<<endl;
}

TEST(ConversorRomanos, QuantidadeAlgarismosIguais)
{
	cout<<endl;
	
	ConversorRomanos test;
	
	string test0 = "I";
	string test1 = "XIX";
	string test2 = "IV";
	string test3 = "DCLXVI";
	string test4 = "MMMDDDCCCLLLXXXVVVIII";
	string test5 = "MMMM";
	string test6 = "MMMDDDD";
	string test7 = "MCLDLLL";
	
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(test0));
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(test1));
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(test2));
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(test3));
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(test4));
	
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(test5));
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(test6));
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(test7));

	cout<<endl;
}

TEST(ConversorRomanos, CaracteresValidos)
{
	cout<<endl;
	
	ConversorRomanos test;
	string algarismos = "CPX";
	
	EXPECT_EQ(0,test.Validar_Caracteres_Validos(algarismos));

	cout<<endl;
}

TEST(ConversorRomanos, CalcularDecimal)
{
	cout<<endl;

	ConversorRomanos test;
	string algarismos = "XXX";
	
	EXPECT_EQ(30,test.Calcular_Decimal(algarismos));

	cout<<endl;
}

TEST(ConversorRomanos, TamanhoString)
{
	cout<<endl;

	ConversorRomanos test;
	string algarismos = "XXX";
	
	EXPECT_EQ(1,test.Validar_Tamanho(algarismos));

	cout<<endl;
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}

