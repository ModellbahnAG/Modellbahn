/**
* @page github Github
*
* @section general Grundsätzliches über Git
*
* Git ist ein Werkzeug zur Versionsverwaltung. Github ist kurz gesagt eine
* Plattform, die Git online anbietet. Normalerweise wird Git über das Terminal
* genutzt. Das ist allerdings nicht für Leute, die noch nie mit dem Terminal
* gearbeitet haben ungewohnt und abschreckend. Deshalb nutzen wir
* <a href="http://desktop.github.com">Github Desktop</a>, ein Programm, das es
* uns ermöglich alle Funktionen von Git in einer übersichtlichen
* Benutzeroberfläche zu nutzen.
*
* @subsection functionality Wie funktioniert Git?
* Das Konzept hinter git ist ganz einfach. Wir speichern unsere Datei mit
* Informationen zu den Änderungen, die seit dem letzten @ref commit "Commit"
* gemacht wurden. So kann man zu jeder Zeit problemlos auf alle älteren Version
* der Datei zurückgreifen können. Zusätzlich können gleichzeitig verschiedene
* "Zweige" an unterschiedlichen Versionen angelegt werden. So kann zum Beispiel
* ein Zweig für eine funktionierende Version und eine Version, in der an neuen
* Funktionen gearbeitet wird, ohne die funktionierende Version zu verlieren.
* Diese Zweige werden @ref branches "Branches" genannt.
*
* @subsection commit Commit
* Als "Commit" kann man sich einfach eine Speicherung der Datei (oder aller
* Dateien im Project) vorstellen. Statt nur zu Speichern, wird aber hier noch
* eine Beschreibung der Änderungen angegeben, um so später genau nachvollziehen
* zu können, wann was geändert wurde.
*
* @subsection sync Synchronisieren
* Da wir die Datei aber nicht nur bei uns lokal gespeichert haben wollen,
* sondern von überall Zugriff auf sie haben möchten, speichern wir das
* Repository (der Ort wo alle unsere Dateien unserers Projekts gespeichert sind)
* woanders. Hierfür verwenden wir Github.
*
* @section handling Bedienung
*
* @subsection diffs Änderungen Anzeigen und committen
* In Github Desktop kann man sich die gemachten Änderungen seit dem letzten
* @ref commit Commit anzeigen lassen, die Änderungen rückgängig gemacht werden
* und die Änderungen commiten. Mit einem Rechtsklick auf eine der geänderten
* Datein kann man die Änderungen mit "Discard changes" rückgängig gemacht
* werden.
* <p>
* Um die Änderungen in Git zu speichern müssen sie commited werden. Dafür muss
* zuerst eine aussagekräftige kurze Beschreibung für die gemachten Änderungen
* als Commit-Beschreibung angegeben werden. Anschließend kann auf Commit
* gedrückt werden, um in den ausgewählten Branch einen @ref commit Commit zu
* machen.
*
* @image html Commit.png width=100%
* @image latex Commit.png width=\textwidth
*
* @subsection pull Push und Pull
* Nach einem @ref commit Commit haben wir also die Änderungen in Git
* gespeichert, allerdings nur lokal bei uns. Um diese auch auf Github zu
* übertragen müssen wir sie pushen. Umgekehrt können wir aber auch Änderungen,
* die wir noch nicht bei uns lokal haben von Github pullen. Sobald man anfängt
* an einem Projekt weiter zu arbeiten sollte man vorher immer pullen um
* sicherzustellen, dass immer mit der neuesten Version gearbeitet wird.
*
* @image html Push-Pull.png width=100%
* @image latex Push-Pull.png width=\textwidth
*
* @subsection branches Branches
* In den Branches kann man, wie bereits erwähnt, an verschiedenen Versionen des
* Projekts gleichzeitig arbeiten. Es empfielt sich einen Branch zu haben, in
* dem nicht gearbeitet wird, sondern in dem jeder Zeit eine funktionsfähige
* Version zu haben. In den anderen Branches kann dann paralllel an verschieden
* Funktionen arbeiten und sie in den "master" oder "main" Branch @ref merge
* mergen sobald sie funktionieren.
*
* @image html Branches-Description.png width=100%
* @image latex Branches-Description.png width=\textwidth
*
* @note Die Branches mit dem Namen @p upstream/... kommen daher, dass dieses
* Repository zuerst auf einem anderen Account erstellt wurde und dann einfach
* geforkt (eine Fork ist eine Abspaltung vom ursrünglichen Porjekt) wurde. Von
* diesen Branches kann nur @ref merge gemerged werden. Bearbeitet werden können
* sie nur vom Besitzer des ursprünglichen Repositorys.
*
* @subsection merge Merge
* Zwei @ref branches Branches zu mergen macht eigentlich genau das, was man sich
* vorstellt, wenn man die Bedeutung des Begriffs im Englischen betrachtet. Zwei
* Branches werden vereint. Dabei werden die Änderungen des Branches, der in den
* Branch, in dem man sich zur Zeit befindet übernommen.
* @note Existieren aber in beiden Branches Änderungen zu dem gleichen Code, ist
* das mergen nicht möchlich.
*/
