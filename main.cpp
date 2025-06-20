#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
using namespace std;
class hang_man
{
private:
    char raide;
    bool laimejo=0;
    string zodis, zodis_2="_________";
    vector<char>strike;
    set<char>spetos_raid;

public:
    hang_man() : raide(0) {
        cout<<"HANG MAN ZAIDIMAS"<<endl;
        cout<<"Si zaidimas yra anglu kalba ir galima suklysti 6 kartus.";
        srand(time(0));
        int i = rand() % 216;
        string word_list[216]={"abruptly", "absurd", "abyss", "affix", "askew", "avenue", "awkward", "axiom", "azure", "bagpipes", "bandwagon", "banjo", "bayou", "beekeeper", "bikini", "blitz", "blizzard", "boggle", "bookworm", "boxcar", "boxful", "buckaroo", "buffalo", "buffoon", "buxom", "buzzard", "buzzing", "buzzwords", "caliph", "cobweb", "cockiness", "croquet", "crypt", "curacao", "cycle", "daiquiri", "dirndl", "disavow", "dizzying", "duplex", "dwarves", "embezzle", "equip", "espionage", "euouae", "exodus", "faking", "fishhook", "fixable", "fjord", "flapjack", "flopping", "fluffiness", "flyby", "foxglove", "frazzled", "frizzled", "fuchsia", "funny", "gabby", "galaxy", "galvanize", "gazebo", "giaour", "gizmo", "glowworm", "glyph", "gnarly", "gnostic", "gossip", "grogginess", "haiku", "haphazard", "hyphen", "iatrogenic", "icebox", "injury", "ivory", "ivy", "jackpot", "jaundice", "jawbreaker", "jaywalk", "jazziest", "jazzy", "jelly", "jigsaw", "jinx", "jiujitsu", "jockey", "jogging", "joking", "jovial", "joyful", "juicy", "jukebox", "jumbo", "kayak", "kazoo", "keyhole", "khaki", "kilobyte", "kiosk", "kitsch", "kiwifruit", "klutz", "knapsack", "larynx", "lengths", "lucky", "luxury", "lymph", "marquis", "matrix", "megahertz", "microwave", "mnemonic", "mystify", "naphtha", "nightclub", "nowadays", "numbskull", "nymph", "onyx", "ovary", "oxidize", "oxygen", "pajama", "peekaboo", "phlegm", "pixel", "pizazz", "pneumonia", "polka", "pshaw", "psyche", "puppy", "puzzling", "quartz", "queue", "quips", "quixotic", "quiz", "quizzes", "quorum", "razzmatazz", "rhubarb", "rhythm", "rickshaw", "schnapps", "scratch", "shiv", "snazzy", "sphinx", "spritz", "squawk", "staff", "strength", "strengths", "stretch", "stronghold", "stymied", "subway", "swivel", "syndrome", "thriftless", "thumbscrew", "topaz", "transcript", "transgress", "transplant", "triphthong", "twelfth", "twelfths", "unknown", "unworthy", "unzip", "uptown", "vaporize", "vixen", "vodka", "voodoo", "vortex", "voyeurism", "walkway", "waltz", "wave", "wavy", "waxy", "wellspring", "wheezy", "whiskey", "whizzing", "whomever", "wimpy", "witchcraft", "wizard", "woozy", "wristwatch", "wyvern", "xylophone", "yachtsman", "yippee", "yoked", "youthful", "yummy", "zephyr", "zigzag", "zigzagging", "zilch", "zipper", "zodiac", "zombie"};

        zodis=word_list[i];

        cout<<"Pasirink zaidimo sunkuma."<<endl;
        cout<<" 1 - bus atskleistos 2 atsitiktinos raides."<<endl;
        cout<<" 2 - bus atskleistos 1 atsitiktina raide."<<endl;
        cout<<" 3 - raides nebus atskleistos"<<endl;
    }
    hang_man(char x) : raide(x){ }
    ~hang_man() {
         if(laimejo==1) {
             cout<<"LAIMEJAI!!!";
         }
        else {
            cout<<"GAME OVER!!!";
        }


    }
    void input() {
        cin >> raide;
    }
    void output() {
        cout<<endl;
        for(char x: strike) {
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i=0; i < zodis.size(); i++) {
            cout<<zodis_2[i]<<" ";
        }
        cout<<endl;
        cout<<"Spetos raides: ";
        for(char x: spetos_raid) {
            cout<<x<<" ";
        }
        cout<<endl;
        cout<<"Koks kitas spejimas? ";

    }
    void tkrinimas() {
        int laimejo_2=0;
        bool atspejo=0;
        spetos_raid.insert(raide);


        for(int i=0; i < zodis.size(); i++) {
            if(zodis[i]==raide) {
                zodis_2[i]=raide;
                laimejo_2++;
                atspejo=1;
                break;
            }
        }
        if(laimejo_2==zodis.size()) {
            laimejo=1;
        }

        if(atspejo==0) {
            strike.push_back('X');
        }



    }
    int get_strike() {
        return strike.size();
    }
    bool get_laimejo() {
        return laimejo;
    }
    void sunkumas() {
        int x;
        srand(time(0));
        int i = rand() % zodis.size();
        srand(time(0));
        int j = rand() % zodis.size();

        while(i==j) {
            j=rand() % zodis.size();
        }

        cin>>x;


        if(x==1) {
            zodis_2[i]=zodis[i];
            zodis_2[j]=zodis[j];
        }
        else if(x==2) {
            zodis_2[i]=zodis[i];
        }

    }
};
int main() {
    hang_man H;

    H.sunkumas();

    while(H.get_strike()<6) {
        H.output();
        H.input();
        H.tkrinimas();
        if(H.get_laimejo()==1) {
            break;
        }
    }

    return 0;
}
