//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet 2 - Calculs Trigo
// Nom du fichier 		: CalculsTrigo.h
// Date de cr�ation 	: 14.02.2024
// Date de modification : 14.02.2024
//
// Auteur 				: Philou (Ph. Bovey)
//
// Description          : 
//
// Remarques			: voir donnee de l'�preuve            
//----------------------------------------------------------------------------------//
#ifndef CALCUL_TRIGO_H
#define CALCUL_TRIGO_H

//-- d�claration -> d�finition globales --// 
#define NB_CHOIX_MAX 2


//-- d�claration -> �num�ration globales --// 
typedef enum { cote, angle } e_choixCoteAngle;
typedef enum { adj = 1, hyp, opp } e_choixCote;
typedef enum { alpha = 1, beta } e_choixAngle;
typedef enum { ok, nok} e_validation;


//-- d�claration -> structure globales --//
//--> structure 1
typedef struct  {
	unsigned char adjacent;
	unsigned char hypotenuse;
	unsigned char oppose;
}str_coteTriangle;
//--> structure 2
typedef struct  {
	float tb_Angle[4]; 
	str_coteTriangle triangle_s;
	struct Str_AetP {
		short air;
		char perimetre;
	};
}str_triangleRectangle;

//-- d�claration de prototype --// 
	//-> tous les champs de la structure seront mis � z�ro
e_validation InitialisationStructure(str_triangleRectangle* pt_strTriangle);
	//-> conversion angle degr� -> en radian 
void Conversion_DegRad(str_triangleRectangle *pt_strTriangle);
	//-> conversion angle radian -> en degr� 
void Conversion_RadDeg(str_triangleRectangle* pt_strTriangle);
	//-> calculer les diff�rents segments du triangle
e_validation CalculeAllAngles (str_triangleRectangle* pt_strTriangle);
	//-> calculer les diff�rents angles 
e_validation CalculeLongeurSegment(str_triangleRectangle* pt_strTriangle);
#endif // !CALCUL_TRIGO_H