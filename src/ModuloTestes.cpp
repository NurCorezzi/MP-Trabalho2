#include "ConversorRomanos.h"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

TEST(ConversorRomanos, ConverterDecimal)
{
	cout<<endl;
	
	ConversorRomanos test;
	
	string testOk1 = "MMCMXXXVIII";	//2938
	string testOk2 = "CDXLIII";		//443
	string testOk3 = "MDCXXXVIII";	//1638
	string testOk4 = "MDCCLXXXVIII";	//1788
	string testOk5 = "MMDCCLXXXVIII";	//2788
	
	EXPECT_EQ(2938,test.Converter_Romano_Decimal(testOk1));
	EXPECT_EQ(443,test.Converter_Romano_Decimal(testOk2));
	EXPECT_EQ(1638,test.Converter_Romano_Decimal(testOk3));
	EXPECT_EQ(1788,test.Converter_Romano_Decimal(testOk4));
	EXPECT_EQ(2788,test.Converter_Romano_Decimal(testOk5));

//----------------------------------------------------------
	
	string badTest1 = "";				//Tamanho invalido
	string badTest2 = "ABCDE";			//Caracter invalido
	string badTest3 = "XXXX";			//Quantidade de algarismos invalida
	string badTest4 = "XIXIXIX";		//Ordem invalida
	
	EXPECT_EQ(0,test.Converter_Romano_Decimal(badTest1));
	EXPECT_EQ(0,test.Converter_Romano_Decimal(badTest2));
	EXPECT_EQ(0,test.Converter_Romano_Decimal(badTest3));
	EXPECT_EQ(0,test.Converter_Romano_Decimal(badTest4));
	
	
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
	
	string testOk1 = "MMMDDDCCCLLLXXXVVVIII";
	
	EXPECT_EQ(1,test.Validar_Quant_Algarismos_Iguais(testOk1));
	
//------------------------------------------------------------------
	
	string badTest1 = "MMMM";
	string badTest2 = "MCCCC";
	string badTest3 = "XIIII";
	
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(badTest1));
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(badTest2));
	EXPECT_EQ(0,test.Validar_Quant_Algarismos_Iguais(badTest3));

	cout<<endl;
}

TEST(ConversorRomanos, CaracteresValidos)
{
	cout<<endl;
	
	ConversorRomanos test;
	
	string testOk1 = "MDCLXVI";
	
	EXPECT_EQ(1,test.Validar_Caracteres(testOk1));
	
//------------------------------------------------------------------
	
	string badTest1 = "XXX*";
	string badTest2 = "XXXA";
	string badTest3 = "XXX9";
	
	EXPECT_EQ(0,test.Validar_Caracteres(badTest1));
	EXPECT_EQ(0,test.Validar_Caracteres(badTest2));
	EXPECT_EQ(0,test.Validar_Caracteres(badTest3));
	cout<<endl;
}

TEST(ConversorRomanos, CalcularDecimal)
{
	cout<<endl;

	ConversorRomanos test;
	//Somente recebe strings corretas
	string testOk1 = "MMCMXXXVIII";	//2938
	string testOk2 = "CDXLIII";	    //443
	string testOk3 = "MDCXXXVIII";	//1638
	
	EXPECT_EQ(2938,test.Calcular_Decimal(testOk1));
	EXPECT_EQ(443,test.Calcular_Decimal(testOk2));
	EXPECT_EQ(1638,test.Calcular_Decimal(testOk3));

	cout<<endl;
}

TEST(ConversorRomanos, TamanhoString)
{
	cout<<endl;

	ConversorRomanos test;
	
	string testOk1 = "MMMCCCDDDIIIOOOCCCLLLMMMNNNSSS";	//30 algarismos	
	string testOk2 = "MMMCCCDDDIIIOOO";					//15 algarismos
	string testOk3 = "M";								//1 algarismo
	
	EXPECT_EQ(1,test.Validar_Tamanho(testOk1));
	EXPECT_EQ(1,test.Validar_Tamanho(testOk2));
	EXPECT_EQ(1,test.Validar_Tamanho(testOk3));
	
//---------------------------------------------------------------------	

	string badTest1 = "MMMCCCDDDIIIOOOCCCLLLMMMNNNSSST";	//31 algarismos	
	string badTest2 = "";									//0 algarismos
	
	EXPECT_EQ(0,test.Validar_Tamanho(badTest1));
	EXPECT_EQ(0,test.Validar_Tamanho(badTest2));

	cout<<endl;
}

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}










