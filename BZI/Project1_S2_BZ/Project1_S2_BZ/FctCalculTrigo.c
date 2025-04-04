//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: FctCalculTrigo.c
// Date de cr�ation 	: 14.02.2024
// Date de modification : 14.02.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : 
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//

//-- definission pour utiliser la lib math sous VS --// 
#define _USE_MATH_DEFINES

//--- librairie standart ---//
#include <stdio.h>
#include <math.h>
//--- librairie perso ---//
#include"CalculTrigo.h"

/* ----------------------------------------------------------------------------------
// -> NOM FCT					: InitialiserStructure 
// -> PARAMETRES ENTRES			: 
// -> PARAMETRE SORTIE			: e_validation 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle 
// -> description				: tous les champs de la structure seront mis � z�ro
 ----------------------------------------------------------------------------------*/
e_validation InitialisationStructure(str_triangleRectangle* pt_strTriangle) {
	//-- d�claration variables --// 
	
	
	//-- pirmaire --// 
	int i;
	//-- enumeration --// 
	e_validation checkFct = 0;
	
	//-- boucle pour initilaiser le tableau des angles --//
	for ( i = 0; i < 4; i++) {
		pt_strTriangle->tb_Angle[i]=0; 
	}

	//-- initialisation des cot�s -> adj - hyp - opp --// 
	pt_strTriangle->triangle_s.adjacent = 0; // pointeur de strucure
	pt_strTriangle->triangle_s.hypotenuse = 0; // pointeur de strucure
	pt_strTriangle->triangle_s.oppose = 0; // pointeur de strucure
	//-- initialisation des champs de air et perim�tres --// 
	pt_strTriangle->air = 0;
	pt_strTriangle->perimetre = 0;
	//-- validation -> de la fct --// 
	checkFct = ok;

	//-- valeur � retourner --// 
	return checkFct;
}

	
/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_DegRad
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: 
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en degr� -> d�terminer sa valeur 
//								  en radian 
 ----------------------------------------------------------------------------------*/

	
void Conversion_DegRad(str_triangleRectangle* pt_strTriangle) {
	//-- test si angle � convertir --//          
	if (pt_strTriangle->tb_Angle[0] != 0) {
		//--> alpha 
		pt_strTriangle->tb_Angle[1] = (float)(M_PI / 180) * pt_strTriangle->tb_Angle[0];
	}
	if (pt_strTriangle->tb_Angle[2] != 0) {
		//--> beta 
		pt_strTriangle->tb_Angle[3] = (float)(M_PI / 180) * pt_strTriangle->tb_Angle[2];
	}

}
/* ----------------------------------------------------------------------------------
// -> NOM FCT					: Conversion_RadDeg
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			:
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: depuis un angle en radian -> d�terminer sa valeur
//								  en degr�
 ----------------------------------------------------------------------------------*/
void Conversion_RadDeg(str_triangleRectangle* pt_strTriangle) {

	//-- test si angle � convertir --//
	if (pt_strTriangle->tb_Angle[1] != 0) {
		//--> alpha 
		pt_strTriangle->tb_Angle[0] = (float)(180/M_PI) * pt_strTriangle->tb_Angle[1];
	}
	if (pt_strTriangle->tb_Angle[3] != 0) {
		//--> beta 
		pt_strTriangle->tb_Angle[2] = (float)(180 / M_PI) * pt_strTriangle->tb_Angle[3];
	}
}
/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculAllAngles
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: si angle rentr� alors alors d�termine le 2�me angle 
 ----------------------------------------------------------------------------------*/


e_validation CalculeAllAngles(str_triangleRectangle* pt_strTriangle) {

	e_validation checkFct = nok;




	//-- si pas d'angle d�fini 
	if ((pt_strTriangle->tb_Angle[0] == 0) &&
		(pt_strTriangle->tb_Angle[1] == 0) &&
		(pt_strTriangle->tb_Angle[2] == 0) &&
		(pt_strTriangle->tb_Angle[3] == 0))
	{
		//-- si cot� non d�fini -> hypoth�nuse -> fonction trigo invers�e arctan 
		if (pt_strTriangle->triangle_s.hypotenuse == 0) {
			pt_strTriangle->tb_Angle[1] = (float)(atan((double)(pt_strTriangle->triangle_s.oppose / (double)pt_strTriangle->triangle_s.adjacent)));


			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);

		}
		//-- si cot� non d�fini -> oppos� -> fonction trigo invers�e arccos
		else if (pt_strTriangle->triangle_s.oppose == 0) {
			pt_strTriangle->tb_Angle[1] = (float)(acos((double)pt_strTriangle->triangle_s.adjacent / (double)pt_strTriangle->triangle_s.hypotenuse));


			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);
		}
		//-- si cot� non d�fini -> adjacent -> fonction trigo invers�e arcsin
		else if (pt_strTriangle->triangle_s.adjacent == 0) {
			pt_strTriangle->tb_Angle[1] = (float)(asin((double)pt_strTriangle->triangle_s.oppose / (double)pt_strTriangle->triangle_s.hypotenuse));

			//-- conversion Radian - Degr� 
			Conversion_RadDeg(pt_strTriangle);
		}
		//-- test si tous les champs sont remplis 
		//-- test si un angle a �t� d�finit alpha ou beta 


	}

	else if (pt_strTriangle->tb_Angle[2] != 0)
		{
			//-- calcul de alpha 
			pt_strTriangle->tb_Angle[0] = 90 - pt_strTriangle->tb_Angle[2];
			//-- conversion Degr� - Radian 
			Conversion_DegRad(pt_strTriangle);
		}
	else if ((pt_strTriangle->tb_Angle[0] != 0))
		{
			//-- calcul de beta
			pt_strTriangle->tb_Angle[2] = 90 - pt_strTriangle->tb_Angle[0];
			//-- conversion Degr� - Radian 
			Conversion_DegRad(pt_strTriangle);
		}
	

	//-- retourne OK 

		return checkFct;
}



/* ----------------------------------------------------------------------------------
// -> NOM FCT					: CalculerLongeursSgements
// -> PARAMETRES ENTRES			:
// -> PARAMETRE SORTIE			: e_validation
// -> PARAMETRE IN/OUT -> ptr	: str_triangleRectangle pt_strTriangle
// -> description				: calculer les diff�rents segments du triangle 
//								  [adjacent - hypoth�nuse - oppos�] 
//								  selon les param�tres ins�rer par l'utilisateur
 ----------------------------------------------------------------------------------*/
e_validation CalculeLongeurSegment(str_triangleRectangle* pt_strTriangle) {
	
	e_validation checkFct=0;
	
	
	//-- test -> si pas aucun angle d�finit 
	if ((pt_strTriangle->tb_Angle[0] == 0) &&
		(pt_strTriangle->tb_Angle[1] == 0) &&
		(pt_strTriangle->tb_Angle[2] == 0) &&
		(pt_strTriangle->tb_Angle[3] == 0))
	{
		CalculeAllAngles(pt_strTriangle);
		//-- test si la valeur � calculer est � z�ro 
		if (pt_strTriangle->triangle_s.adjacent == 0) {
			//CalculeAllAngles(pt_strTriangle);
			//-- calculer segment adjacent --//
			pt_strTriangle->triangle_s.adjacent = sqrt(pow((double)pt_strTriangle->triangle_s.hypotenuse, 2) - (pow((double)pt_strTriangle->triangle_s.oppose, 2)));
		}
		//-- calculer segment hypoth�nuse --// 
		else if (pt_strTriangle->triangle_s.hypotenuse == 0) {
			//CalculeAllAngles(pt_strTriangle);
			//-- calculer segment adjacent --//
			pt_strTriangle->triangle_s.hypotenuse = sqrt(pow((double)pt_strTriangle->triangle_s.adjacent, 2) + (pow((double)pt_strTriangle->triangle_s.oppose, 2)));
		}
		//-- calculer segment oppos� 
		else if (pt_strTriangle->triangle_s.oppose == 0) {
			//CalculeAllAngles(pt_strTriangle);
			//-- calculer segment adjacent --//
			pt_strTriangle->triangle_s.oppose = sqrt(pow((double)pt_strTriangle->triangle_s.hypotenuse, 2) - (pow((double)pt_strTriangle->triangle_s.adjacent, 2)));
		}
		
	} 

	
		//-- test si un angle a �t� d�finit alpha ou beta 
	else if ((pt_strTriangle->tb_Angle[0] != 0) || (pt_strTriangle->tb_Angle[2] != 0))
	{
		
		//-- test si l'angle alpha a �t� ins�r� 
		if (pt_strTriangle->tb_Angle[0] != 0) {
			//-- conversion de alpha -> � -> radian 
			Conversion_DegRad(pt_strTriangle);

			//-- test si sgement hypoth�nuse entr� 
			if (pt_strTriangle->triangle_s.hypotenuse != 0) {


				//Calcul -> cos(alpha) = adj / hyp => ... 
				pt_strTriangle->triangle_s.adjacent = cos(pt_strTriangle->tb_Angle[1]) * pt_strTriangle->triangle_s.hypotenuse;

				//Calcul -> sin(alpha) = opp / hyp => ...
				pt_strTriangle->triangle_s.oppose = sin(pt_strTriangle->tb_Angle[1]) * pt_strTriangle->triangle_s.hypotenuse;


			}
			//-- test si sgement adjacent entr� 
			else if (pt_strTriangle->triangle_s.adjacent != 0) {
				//Calcul -> cos(alpha) = adj/hyp => ...
				pt_strTriangle->triangle_s.hypotenuse = pt_strTriangle->triangle_s.adjacent / cos(pt_strTriangle->tb_Angle[1]);
				//Calcul -> tan(alpha) = opp/adj => ...
				pt_strTriangle->triangle_s.oppose = pt_strTriangle->triangle_s.adjacent * tan(pt_strTriangle->tb_Angle[1]);


			}
			//-- test si sgement oppos� entr�  
			else if (pt_strTriangle->triangle_s.oppose != 0) {
				//Calcul -> sin(alpha) = opp/hyp => ...
				pt_strTriangle->triangle_s.hypotenuse = pt_strTriangle->triangle_s.oppose / sin(pt_strTriangle->tb_Angle[1]);

				//Calcul -> tan(alpha) = opp/adj => ... 
				pt_strTriangle->triangle_s.adjacent = pt_strTriangle->triangle_s.oppose / tan(pt_strTriangle->tb_Angle[1]);
			}
			
			
		}
		
		//-- calcul de tous les angles -> appel de fct --// 

	}	CalculeAllAngles(pt_strTriangle);

//-- check si la longeur des segments bien calcul� 
	return checkFct;

}











