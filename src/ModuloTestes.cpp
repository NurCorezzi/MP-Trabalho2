#include "ConversorRomanos.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

TEST(ConversorRomanos, ConverterDecimal)
{
	cout<<endl;
	
	ConversorRomanos test;
	
	string testOk1 = "MMCMXXXVIII";
	string testOk2 = "CDXLIII";
	
	EXPECT_EQ(2938,test.Converter_Romano_Decimal(testOk1));
	EXPECT_EQ(443,test.Converter_Romano_Decimal(testOk2));

//----------------------------------------------------------

	
	
	cout<<endl;
}


TEST(ConversorRomanos, FormatoValido)
{
	cout<<endl;
	
		ConversorRomanos test;
	
	string testOk1 = "MMCMXXXVIII";
	string testOk2 = "CDXLIII";
	
	EXPECT_EQ(1,test.Validar_Ordem_Algarismos(testOk1));
	EXPECT_EQ(1,test.Validar_Ordem_Algarismos(testOk2));

//------------------------------------------------------------
	
	//Para ambos casos errados de I
	string badTest1 = "IL";
	string badTest2 = "IXI";
	
	//Para casos errados de V
	string badTest3 = "VV";
	
	//Para ambos casos errados de X
	string badTest4 = "XD";
	string badTest5 = "XCX";
	
	//Para casos errados de L
	string badTest6 = "LL";
	
	//Para casos errados de C
	string badTest7 = "CDC";
	
	//Para casos errados de D
	string badTest8 = "DD";
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest1));
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest2));
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest3));
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest4));
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest5));
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest6));
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest7));
	
	EXPECT_EQ(0,test.Validar_Ordem_Algarismos(badTest8));

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

