package live;

import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class Test {
    public static void main(String[] args) {

        Veena v = new Veena();
        Saxophone s = new Saxophone();

        // Direct method calls
        v.play();
        s.play();

        // Using interface reference
        Playable p;

        p = v;
        p.play();

        p = s;
        p.play();
    }
}
