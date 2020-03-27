# ei-o-mat
Smarte Eieruhr
Berechnung der erforderlichen Kochzeit für die gewünschte Eigelbkonsistenz.
Anschließend ein Timer der abläuft.

Quellen: 
  https://www.springlane.de/magazin/ei-kochen-anleitung/amp/
  https://www.eierfans.de/eirechner-wie-lange-eier-kochen/ (Formeln fürs eierkochen)
  http://newton.ex.ac.uk/teaching/CDHW/egg/ (Formeln fürs eierkochen)

Zwischenziele:

> Timerfunktion?

> Formel zur Berechnung der Zeit:
  Formel von Charles Williams  https://www.eierfans.de/eirechner-wie-lange-eier-kochen/
    t = L*m^(2/3)*ln(0.76 *(T_wasser-T_start)/(T_wasser-T_ende))
    L   ist abhängig von den Eigelb und Eiklar (Eigelb: L = 0.517, Eiklar: L = 0.450)
        bei 33% Eigelb und 67% Eiklar ergibt sich 
    L = 0.47211
    Zusätzliche anpassung der Formel basierend auf empfehlungen von https://www.eierfans.de ist ein kürzung der Zeit um 10%.
  Daraus ergibt sich folgende Formel:
    t = 0.47211*m^(2/3)*ln(0.76 *(T_wasser-T_start)/(T_wasser-T_ende)) * 0,9
    Nach ausgiebigen Tests kann der Korrekturfaktor 0,9 noch angepasst werden.
    
> Welche Abfragen braucht man? Wie beeinflussen diese die Kochzeit?
      Benötigte größen für Formel: 
        > Masse
        > Wassertemperatur
        > Anfangstemperatur vom  Ei
        > Zieltemperatur vom Eigelb
  
    > Masse: 
        > nach Gewicht
        > nach XL, L, M, S
              S: unter 53 g     >> 48 g
              M: 53 g bis 63 g  >> 58 g
              L: 63 g bis 73 g  >> 68 g
              XL: über 73 g     >> 78 g
    > Wassertemperatur: (Temperatur bei der Wasser das Wasser kocht)
        > Höhe über Meer (Karlsruhe oder eigener Wert)      
            > T_wasser bei 0 m über NHN = 100°C
            > T_wasser sinkt etwa um 0,003354°C pro Meter über NHN
    > Anfangstemperatur vom Ei:
        > Eier aus Kühlschrank (4°C), Zimmertemperatur (20°C) oder anderer Lagertemperatur?
    > Zieltemperatur vom Eigelb:
        > Wie frisch sind die Eier? (Auswirkungen darauf bei welcher Temperatur das Eigelb fest wird)
            > Frische eier: Flüssiger Dotter – 62 Grad
                            Weicher Dotter – 67 Grad
                            Hartes Ei – 82 Grad
            > alte Eier sind schneller fertig. 
        > Wie soll die Konsistenz der Eier sein? 
    
   
    
    > 
