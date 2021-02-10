/**
* @page platformio PlatformIO
* @section Einleitung
* PlatformIO ist kein eigenstädniger Editor, sondern ein Plugin, welches für
* verschiedene Editoren verfügbar ist. Wir nutzen PlatformIO in Atom. Das ist
* aber für die Bedienung von @p PlatformIO nicht wichtig.
*
* @section newproject Ein neues Projekt erstellen
* Anders als bei der Arduino IDE können wir nicht einfach PlatformIO öffnen und
* direkt drauf los programmieren, sondern müssen zuerst ein neues Projekt
* erstellen. \n
* Dafür müssen wir im <tt> Home Tab </tt> von PlatformIO <tt>"New Project"</tt>
* wählen und das neue Projekt konfigurieren. Geöffnet wird der <tt>Home Tab</tt>
* mit dem Knopf
* @image{inline} html Home.png width=5%
* @image{inline} latex Home.png width=5%
*
* Jetzt muss das neue Projekt konfiguriert werden. Als Name sollte ein
* aussagekräftiger Name gewählt werden, damit das Pfojekt auch später wieder
* gefunden wird. Als Board wird der Typ des Arduinos angegeben, in den meisten
* Fällen ist das der <tt>Arduino Uno</tt>. Dies lässt sich später noch in der
* @ref platformioini <tt>platformio.ini</tt> Datei anpassen. Als Framework
* MUSS Arduino ausgewählt sein. Um Github nutzen zu können, muss das Projekt im
* Ordner @p Modellbahn oder in einem seiner Unterordner gespeichert sein. \n
* Sobald das Projekt erstellt wurde, kann in der sich im @p src Ordner
* befindenden <tt>main.cpp</tt> Datei das Programm geschrieben werden.
*
* @image html New_Project_Description.png width=100%
* @image latex New_Project_Description.png width=\textwidth
*
* @section libraries Bibliotheken / Libraries hinzufügen
* Die verwendeten Libraries müssen in der @ref platformioini platformio.ini
* Datei eingetragen werden, damit sie verwendet werden können. Glücklicherweise
* müssen wir das aber nicht selber tun, sondern können dafür die @p Libraries
* Funktion von PlatformIO nutzen. Diese verbirgt sich im @p Home Tab hinter dem
* Knopf
* @image{inline} html Libraries.png width=5%
* @image{inline} latex Libraries.png width=5%
* \n
* Dort können alle verfügbaren Libraries durch sucht werden und dann mit
* <tt>Add to Project</tt> zu einem bestimmten Projekt hinzugefügt werden. Alle
* nötigen Einträge in die @ref platformioini platformio.ini Datei werden
* automatisch gemacht. \n
* Es gibt jedoch eine Library, die dort nicht zu finden sein wird, die
* @p Modellbahn Library. Der Grund dafür ist, dass es unsere eigene ist, die wir
* nicht veröffentlicht haben. Um diese nutzen zu können, müssen wir dann doch in
* die @ref platformioini platformio.ini Datei und Folgende Zeile einfügen:
* {@code lib_deps = https://github.com/ModellbahnAG/Libraries-Modellbahn.git}
*
*
* @section programming Programmieren
* Wer die schon mit Arduino programmiert hat, sollte auch mit PlatformIO zurecht
* kommen, da alles genau so programmiert wird wie mit der Arduino IDE.
*
* @image html Editor_Description.png width=100%
* @image latex Editor_Description.png width=\textwidth
*
* @subsection upload Hochladen
* @image{inline} html Upload.png width=5%
* @image{inline} latex Upload.png width=5%
*
* Dieser Knopf lädt das Programm auf den Arduino hoch.
*
* @subsection build Build
* @image{inline} html Compile.png width=5%
* @image{inline} latex Compile.png width=5%
*
* Dieser Knopf kompiliert den Code. Wenn euch das nichts sagt, ist das nicht
* schlimm, wichtig ist nur, dass genau das gleiche passiert wenn ihr hochladen
* drückt, nur ohne das das Programm auf den Arduino hochgeladen wird. Das
* Programm wird lediglich in eine für den Arduino verständliche Sprache
* übersetzt. Dabei werden auch schon die Fehler gefunden, die ein Hochladen
* verhindern würden.
*
* @subsection serialmonitor Serieller Monitor
* @image{inline} html Serial_Monitor.png width=5%
* @image{inline} latex Serial_Monitor.png width=5%
*
* Dieser Knopf öffnet den seriellen Monitor, über den die Ausgaben des Arduinos
* angezeigt werden.
*
* @section platformioini Konfiguration mit platformio.ini
* In der <tt>platformio.ini</tt> Datei können im Nachhinein noch einige
* Konfigurationen angepasst werden und weitere hinzugefügt werden. Die
* wichtigsten Dabei sind das Board und die verwendeten Libraries. Um die
* @p Modellbahn Library verwenden zu können, die Library, in der schon einige
* häufig gebrauchten Funktionen für den Modellbau programmiert sind, muss der
* Github Link zu dem Repository angegeben werden. Das machen wir mit folgender
* Zeile:
* {@code lib_deps = https://github.com/ModellbahnAG/Libraries-Modellbahn.git}
*
* @image html Platform.ini_Description.png width=100%
* @image latex Platform.ini_Description.png width=\textwidth
*/
