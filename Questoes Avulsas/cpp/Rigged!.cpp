#include <iostream>
using namespace std;

int main()
{
    int num_testes;
    cin >> num_testes;
    for (int i=0; i<num_testes; i++)
    {
        int num_participantes;

        cin >> num_participantes;

        int forcapoly;
        int resistenciapoly;

        cin >> forcapoly;
        cin >> resistenciapoly;
        int peso = forcapoly;

        for (int j=1; j<num_participantes; j++)
        {   
            int forca;
            int resistencia;

            cin >> forca >> resistencia;
            if (forca >= forcapoly && resistencia >= resistenciapoly)
            {
                peso = -1;
            }
        }
        cout << peso << endl;
    }
}
