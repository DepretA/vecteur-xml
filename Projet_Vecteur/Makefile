.PHONY: main
main: Main.cpp tinyXML/*.cpp vecteurPlan2D/*.cpp vecteurXML/*.cpp
	g++ tinyXML/*.cpp vecteurPlan2D/*.cpp vecteurXML/*.cpp Main.cpp -o main
clean:
	rm -rf *~
mrproper: clean
	rm -f main
