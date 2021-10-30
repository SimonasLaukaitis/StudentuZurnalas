
#
# StudentuZurnalas

**Reikalingų duomenų sąrašas:**
--
1. Norimų įvesti studentų skaičius
2. Studento vardas
3. Studento pavardė
4. Studento pažymiai
----
## Jeigu failas yra tuščias:
* Programa paprašo pasirinkti skaičiuosite vidurkį, ar medianą
* Programa paprašo pasirinkti **NORMAL MODE** (duomenys bus įvedami vartotojo), arba **DEMO MODE** (duomenys bus gneruojami) 
* Paklausiama kiek stidentų objektų kursime
* Priklausomai nuo pasirinkto objektų skaičiaus įvedama studėnto duomenys(vardas ir pavardė)
* Įvedami pažymiai, egzamino pažymys. 
	>**Note:** norint nutraukti pažymių įvedimą sirenkama `-1` . 
* Sukuriami objektai, paskaičiuojamas medianas arba vidurkis
* Studentai surūšiuojami abėcėline tvarka
* Viskas įrašoma į failą

## Jeigu failas yra ne tuščias:
* Programa paprašo pasirinkti **NUSKAITYTI** ar **VALYTI** failus (pasirinkus **VALYTI** gržtama į programos pradžią)
* Pasirinkus **NUSKAITYTI** klausiama kaip norėsite nuskaityti
     * **TESTAVIMAS**   
		  > **Note:** testavimo rėžimas skirtas įvariems konteinerių tipams 
		  testuoti, skaičiuoti vykdymo laiką
     * Per buferį `gudruciai.txt`
     * Per buferį `nuskriaustukai.txt`
     * Paprastas nuskaitymas, po vieną simbolį `kursiokai.txt`
     * Paprastas nuskaitymas `gudruciai.txt` ir `nuskriaustukai.txt`
 * Baigus išvedimą grįžtama į ekraną kur klausiama **NUSKAITYTI** ar **VALYTI** failus 
 
## Programos veikimp pavyzdys
`Failas yra tuscias!`
`Irasomi nauji duomenys`

`Vidurkis: 1`
`Medianas: 2`
   > NOTE pasirenkamas **Vidurkis**
   
`NORMAL MODE: 1`
`DEMO MODE: 2`
   > NOTE pasirenkamas **Demo mode**
 
`Kiek objektu kursim: 4`
`Kiek pazimiu generuosim: 3`
> NOTE įvedamas objektų ir  pažymių skaičius

`1. ***STUDENTO OBJEKTAS SUKURTAS***`
`2. ***STUDENTO OBJEKTAS SUKURTAS***`
`3. ***STUDENTO OBJEKTAS SUKURTAS***`
`4. ***STUDENTO OBJEKTAS SUKURTAS***`

**Toliau programa pradeda veikti iš pradžių**
`Faile yra duomenu!`
`1. FAILU NUSKAITYMAS`
`2. FAILU VALYMAS`
> NOTE pasirenkamas **FAILU NUSKAITYMAS**
> 
`KAIP NORESITE ISVESTI`
`1. *TESTAVIMAS* Per buferi kursiokai.txt`
`2. Per buferi gudrociai.txt`
`3. Per buferi nuskriaustukai.txt`
`4. Paprastai kursiokai.txt`
`5. Paprastai gudrociai.txt ir nuskriaustukai.txt`
> NOTE pasirenkamas **Paprastai gudrociai.txt ir nuskriaustukai.txt**

`****************************GALVOCIAI****************************`
`Galvocius 1.Vardas   Pavarde     4  9  1    8   (Vid) 6.67`
`Galvocius 3.Vardas   Pavarde     6  3  8    5   (Vid) 5.27`
`Galvocius 5.Vardas   Pavarde     8  4  8    6   (Vid) 6.66`
`****************************NUSKRIAUSTUKAI***********************`
`Nuskriaustukas 2.Vardas   Pavarde     2  1  9    0   (Vid) 1.60`
`Nuskriaustukas 4.Vardas   Pavarde     5  5  3    3   (Vid) 3.53`
`

**Toliau grįžtama į programos pradžią**
`Faile yra duomenu!`
`1. FAILU NUSKAITYMAS`
`2. FAILU VALYMAS`

## Programos veikimo etapai ir jų realizavimas
1. Versija *v0.1*
	* Masyvų, vėliau vektorių programoje naudojimas
	* Rašymas/skaitymas iš failo (Norint įrašyti reikia išvalyti `SETTINGS.TXT` ir `kursiokai.TXT` failus, kitaip skaitys tai kas jau yra failuose) 
	* Kodas padalintas i kelis failus ( *Refactoring* ) 
	* Įdėti destruktoriai ir masyvų valymo funkcijos vietos atlaisvinimui
	* Leidžia paimti 1 000 000 objektų 
	* Formatuotas tekstas faile ir išvedime 
	* Medianas, bei vidurkio skaiciavimas 
	* Įvedant ranka, jei objektų pažymių skaičius skiriasi, tuščios vietos pakeičiamas nuliais
2. Versija *v0.2*
      * Rušiuoja duomenis į "Gudročius" ir "Nuskriaustukus"
      * "Gudročius" ir "Nuskriaustukus" išveda i du naujus failus
      *  **Duomenų spartos analizė yra pridėtame `"testavimas.xlsx"` faile**
      >NOTE:  Duomenų talpinimą greičiausiai vykdė *Vector*, bet tik kol skaičiai maži, `sort()` funkcija veikė pakankamai lėtai, lyginti su kitais
      *List* duomenis talpino lėtai, lyginti su *Vector* ir *Deque*, tačiau sort funkcija veikė greitai, bet su didesniais skaičiais nusileido *Deque*.
      *Deque* duomenis talpino lėčiausiai, bet greičiausias buvo duomenų rūšiavime, kai duomenys pasiekdavo 100 000 ir daugiau.
3. Versija *v1.0*
	* Įgyvendinta **1 strategija**: Bendro **studentai** konteinerio (`vector`, `list` ir `deque` tipų) skaidymas (rūšiavimas) **į du naujus to paties tipo konteinerius**
	>NOTE: Kadangi šis etapas buvo vykdomas nuskaitant per buferį, rezultatai skiriasi lyginant su pirmuoju testavimu. Failų nuskaityme dideliuose objektų skaičiuose greičiausiai veikė *List*, sort() - *Deque*. Duomenys panašūs kaip ir ankstesniame testavime.  Mažiausiai atminties pareikalavo **VECTOR** konteineris 
	* Įgyvendinta **2 strategija**: Bendro studentų konteinerio (`vector`, `list` ir `deque`) skaidymas (rūšiavimas) **panaudojant tik vieną naują konteinerį**: "**nuskriaustukai**".
	>NOTE: Šiuo būdu *sort()* funkcija visais atvėjais veikė greičiau, rūšiavimas į du konteinerius vyko žymiai lėčiau, nepriklausomai nuo konteinerio tipo, bet greičiausias buvo *Deque*. Išvedimas i vieną naują failą ir likusių palikimas užtruko itin trumpai, lyginant su vedimu į du atskirus failus. Atminties poreikis sumažėjo itin stipriai ~5 kartus.
	*(pirmos ir antros strategijos duomenys gali skirtis, nes buvo modifikuotas nuskaitymas iš failo)* 
	* Nauji testavimo duomenys aprašyti `Testavimas Buferis.xlsx` faile *(nuskaitoma per buferį)*

