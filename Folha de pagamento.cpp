#include <stdio.h>
#include <locale.h>


float fsal_familia (int qt_dep14, float sal1) //salario familia
{
	float result;
	if ((qt_dep14 > 0) && (sal1<=1425.56))
		result=(48.62*qt_dep14);
	else
		result=0;
	return result;
}
float fval_inss (float sal1)  //inss
{
	float result;
	if (sal1<=1045.00)
		result=(sal1*0.075);
	else
		if (sal1<= 2089.60)
			result=(sal1*0.09);
		else
			if (sal1<=3134.40)
				result=(sal1*0.12);
			else
				if (sal1<=6101.06)
					result=(sal1*0.14);
				else
					result=(6101.06*0.14);
	return result;
}
float ffgts (float sal1) //fgts
{
	float result;
	result=sal1*0.08;
	return result;
}
float fir (float sal1, float val_inss, int qt_dep21) //ir
{
	float result, base_ir;
	base_ir=(sal1-val_inss-(qt_dep21*189.59));
	if (base_ir<=1903.98)
		result=0;
	else
		if (base_ir<=2826.65)
			result=(base_ir*0.075)-142.80;
		else
			if (base_ir<=3751.05)
				result=(base_ir*0.15)-354.80;
			else
				if (base_ir<=4664.68)
					result=(base_ir*0.225)-636.13;
				else
					result=(base_ir*0.275)-869.36;
	return result;	
}
float fsal_liq (float sal1, float val_inss, float sal_familia, float ir)  //salário líquido
{
	float result;
	result=sal1-val_inss+sal_familia-ir;
	return result;
}
main()
{
	setlocale(LC_ALL, "Portuguese");
	char nome_func[30];
	int qt_dep14, qt_dep21;
	float sal_bruto, sal_grat, sal_familia, fgts, val_inss, sal1, base_ir, ir, sal_liq; 	

	printf ("Nome do funcionário:");
	scanf (" %s", &nome_func);
	printf ("\nQuantidade de dependente até 14 anos:");
	scanf (" %d", &qt_dep14);
	printf ("\nQuantidade de dependente com idade até 21 anos:");
	scanf (" %d", &qt_dep21);
	printf ("\nSalário Bruto:");
	scanf (" %f", &sal_bruto);
	printf ("\nSalário extra ou gratificação:");
	scanf (" %f", &sal_grat);
	
	sal1=sal_bruto+sal_grat;
	sal_familia=fsal_familia(qt_dep14, sal1);
	val_inss=fval_inss(sal1);
	fgts=ffgts(sal1);
	ir=fir(sal1,val_inss, qt_dep21);
	sal_liq=fsal_liq(sal1,val_inss,sal_familia,ir);
		
	printf ("\nNome do funcionário: %s", nome_func);
	printf ("\nSalário Bruto: %.2f", sal1);
	printf ("\nSalário família: %.2f", sal_familia);
	printf ("\nValor INSS: %.2f", val_inss);
	printf ("\nValor FGTS: %.2f", fgts);
	printf ("\nValor IR: %.2f", ir);
	printf ("\nO Salário Líquido é: %.2f", sal_liq);	
}
	
