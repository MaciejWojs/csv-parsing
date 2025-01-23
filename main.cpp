#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include "CSV-Parser.hpp"
#include "recordsTree.hpp"

int main() {
    CSVParser parser("Chart-Export.csv");
    std::vector<Record> records = parser.parse();


    // for (const auto& record : records) {
    //     std::cout << record << std::endl;
    // }

    std::cout << "Ilosc rekordow: " << records.size() << std::endl;

    RecordsTree tree;
    for (const auto& record : records) {
        tree.addRecord(record);
    }

    tree.sortRecords();
    // tree.printTree();
    // tree.printRecord();

    // double sum1 = tree.getAutoConsumptionSum(records, "01.10.2020 8:00", "01.10.2020 9:30");
    // double sum2 = tree.getExportSum(records, "01.10.2020 8:00", "01.10.2020 9:30");
    // double sum3 = tree.getImportSum(records, "01.10.2020 8:00", "01.10.2020 9:30");
    // double sum4 = tree.getConsumptionSum(records, "01.10.2020 8:00", "01.10.2020 9:30");
    // double sum5 = tree.getProductionSum(records, "01.10.2020 8:00", "01.10.2020 9:30");

    // tree.printRecordsBetweenTimes("01.10.2020 8:00", "01.10.2020 9:30");


    // std::cout << "Ilosc rekordow pomiedzy 8:00 a 9:30: " << tree.getNumberOfItemsBetweenTimes(records, "01.10.2020 8:00", "01.10.2020 9:30") << std::endl;

    // tree.compareAutoConsumption(records, "01.10.2020 8:00", "01.10.2020 9:30", "01.10.2020 9:45", "01.10.2020 10:45");
    // tree.compareExport(records, "01.10.2020 8:00", "01.10.2020 9:30", "01.10.2020 9:45", "01.10.2020 10:45");
    // tree.compareImport(records, "01.10.2020 8:00", "01.10.2020 9:30", "01.10.2020 9:45", "01.10.2020 10:45");
    // tree.compareProduction(records, "01.10.2020 8:00", "01.10.2020 9:30", "01.10.2020 9:45", "01.10.2020 10:45");
    // tree.compareConsumption(records, "01.10.2020 8:00", "01.10.2020 9:30", "01.10.2020 9:45", "01.10.2020 10:45");

    //------------------------------------------------------------------------------------------------------------

    enum class Operation {
        PrintRecordsBetweenTimes = 1,
        CompareAutoConsumption,
        CompareExport,
        CompareImport,
        CompareConsumption,
        CompareProduction,
        GetAutoConsumptionSum,
        GetExportSum,
        GetImportSum,
        GetConsumptionSum,
        GetProductionSum,
        GetAutoConsumptionAverage,
        GetExportAverage,
        GetImportAverage,
        GetConsumptionAverage,
        GetProductionAverage,
        SearchThroughRecords,
        Exit
    };

    while (true) {
        std::cout << "1. Wyswietl rekordy pomiedzy dwoma godzinami" << std::endl;
        std::cout << "2. Porownaj autokonsumpcje pomiedzy dwoma okresami" << std::endl;
        std::cout << "3. Porownaj eksport pomiedzy dwoma okresami" << std::endl;
        std::cout << "4. Porownaj import pomiedzy dwoma okresami" << std::endl;
        std::cout << "5. Porownaj konsumpcje pomiedzy dwoma okresami" << std::endl;
        std::cout << "6. Porownaj produkcje pomiedzy dwoma okresami" << std::endl;
        std::cout << "7. Suma autokonsumpcji w okresie" << std::endl;
        std::cout << "8. Suma eksportu w okresie" << std::endl;
        std::cout << "9. Suma importu w okresie" << std::endl;
        std::cout << "10. Suma konsumpcji w okresie" << std::endl;
        std::cout << "11. Suma produkcji w okresie" << std::endl;
        std::cout << "12. Srednia autokonsumpcji w okresie" << std::endl;
        std::cout << "13. Srednia eksportu w okresie" << std::endl;
        std::cout << "14. Srednia importu w okresie" << std::endl;
        std::cout << "15. Srednia konsumpcji w okresie" << std::endl;
        std::cout << "16. Srednia produkcji w okresie" << std::endl;
        std::cout << "17. Wyszukaj rekordy" << std::endl;
        std::cout << "18. Wyjdz" << std::endl;

        int switchOperation{};
        std::cin >> switchOperation;

        auto operation = static_cast<Operation>(switchOperation);

        switch (operation) {
        case Operation::PrintRecordsBetweenTimes:
            {
                std::string time1, time2;
                std::cout << "Podaj pierwsza godzine: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj druga godzine: ";
                std::getline(std::cin, time2);
                tree.printRecordsBetweenTimes(time1, time2);
                break;
            }
        case Operation::CompareAutoConsumption:
            {
                std::string time1_begin, time1_end, time2_begin, time2_end;
                std::cout << "Podaj poczatek pierwszego okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1_begin);
                std::cout << "Podaj koniec pierwszego okresu: ";
                std::getline(std::cin, time1_end);
                std::cout << "Podaj poczatek drugiego okresu: ";
                std::getline(std::cin, time2_begin);
                std::cout << "Podaj koniec drugiego okresu: ";
                std::getline(std::cin, time2_end);

                tree.compareAutoConsumption(records, time1_begin, time1_end, time2_begin, time2_end);
                break;
            }
        case Operation::CompareExport:
            {
                std::string time1_begin, time1_end, time2_begin, time2_end;
                std::cout << "Podaj poczatek pierwszego okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1_begin);
                std::cout << "Podaj koniec pierwszego okresu: ";
                std::getline(std::cin, time1_end);
                std::cout << "Podaj poczatek drugiego okresu: ";
                std::getline(std::cin, time2_begin);
                std::cout << "Podaj koniec drugiego okresu: ";
                std::getline(std::cin, time2_end);

                tree.compareExport(records, time1_begin, time1_end, time2_begin, time2_end);
                break;
            }
        case Operation::CompareImport:
            {
                std::string time1_begin, time1_end, time2_begin, time2_end;
                std::cout << "Podaj poczatek pierwszego okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1_begin);
                std::cout << "Podaj koniec pierwszego okresu: ";
                std::getline(std::cin, time1_end);
                std::cout << "Podaj poczatek drugiego okresu: ";
                std::getline(std::cin, time2_begin);
                std::cout << "Podaj koniec drugiego okresu: ";
                std::getline(std::cin, time2_end);

                tree.compareImport(records, time1_begin, time1_end, time2_begin, time2_end);
                break;
            }
        case Operation::CompareConsumption:
            {
                std::string time1_begin, time1_end, time2_begin, time2_end;
                std::cout << "Podaj poczatek pierwszego okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1_begin);
                std::cout << "Podaj koniec pierwszego okresu: ";
                std::getline(std::cin, time1_end);
                std::cout << "Podaj poczatek drugiego okresu: ";
                std::getline(std::cin, time2_begin);
                std::cout << "Podaj koniec drugiego okresu: ";
                std::getline(std::cin, time2_end);

                tree.compareConsumption(records, time1_begin, time1_end, time2_begin, time2_end);
                break;
            }
        case Operation::CompareProduction:
            {
                std::string time1_begin, time1_end, time2_begin, time2_end;
                std::cout << "Podaj poczatek pierwszego okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1_begin);
                std::cout << "Podaj koniec pierwszego okresu: ";
                std::getline(std::cin, time1_end);
                std::cout << "Podaj poczatek drugiego okresu: ";
                std::getline(std::cin, time2_begin);
                std::cout << "Podaj koniec drugiego okresu: ";
                std::getline(std::cin, time2_end);

                tree.compareProduction(records, time1_begin, time1_end, time2_begin, time2_end);
                break;
            }


        case Operation::GetAutoConsumptionSum:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double sum = tree.getAutoConsumptionSum(records, time1, time2);
                std::cout << "Suma autokonsumpcji: " << sum << std::endl;
                break;
            }
        case Operation::GetExportSum:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double sum = tree.getExportSum(records, time1, time2);
                std::cout << "Suma eksportu: " << sum << std::endl;
                break;
            }
        case Operation::GetImportSum:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double sum = tree.getImportSum(records, time1, time2);
                std::cout << "Suma importu: " << sum << std::endl;
                break;
            }
        case Operation::GetConsumptionSum:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double sum = tree.getConsumptionSum(records, time1, time2);
                std::cout << "Suma konsumpcji: " << sum << std::endl;
                break;
            }
        case Operation::GetProductionSum:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double sum = tree.getProductionSum(records, time1, time2);
                std::cout << "Suma produkcji: " << sum << std::endl;
                break;
            }
        case Operation::GetAutoConsumptionAverage:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double avg = tree.getAutoConsumptionAverage(records, time1, time2);
                std::cout << "Srednia autokonsumpcji: " << avg << std::endl;
                break;
            }
        case Operation::GetExportAverage:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double avg = tree.getExportAverage(records, time1, time2);
                std::cout << "Srednia eksportu: " << avg << std::endl;
                break;
            }
        case Operation::GetImportAverage:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double avg = tree.getImportAverage(records, time1, time2);
                std::cout << "Srednia importu: " << avg << std::endl;
                break;
            }
        case Operation::GetConsumptionAverage:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double avg = tree.getConsumptionAverage(records, time1, time2);
                std::cout << "Srednia konsumpcji: " << avg << std::endl;
                break;
            }
        case Operation::GetProductionAverage:
            {
                std::string time1, time2;
                std::cout << "Podaj poczatek okresu: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, time1);
                std::cout << "Podaj koniec okresu: ";
                std::getline(std::cin, time2);

                double avg = tree.getProductionAverage(records, time1, time2);
                std::cout << "Srednia produkcji: " << avg << std::endl;
                break;
            }

        case Operation::SearchThroughRecords:
            {

                int selectedSearchOperation{};
                double value{};
                double tolerance{};
                std::string time{};

                //TODO

                while (true) {
                    std::cin >> selectedSearchOperation;
                    if (selectedSearchOperation >= static_cast<int>(SearchOperation::SearchByTime) && selectedSearchOperation <= static_cast<int>(SearchOperation::SearchByProduction)) {

                        break;
                    }
                    std::cerr << "Niepoprawna operacja" << std::endl;
                }
                auto searchOperation = static_cast<SearchOperation>(selectedSearchOperation);


                break;
            }




        case Operation::Exit:
            return 0;
        default:
            std::cout << "Niepoprawna operacja" << std::endl;
            break;
        }
        std::cout << "Nacisnij enter aby kontynuowac...\n";
        std::cin.get();
    }
}