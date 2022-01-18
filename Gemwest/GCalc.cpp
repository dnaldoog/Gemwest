#include "pch.h"
#include "GCalc.h"
String^ GCalc::gem_round_formula(void) {
    //Double calculate;
    //String^ sg = returnSG();
    //String^ depth = returnDepth();
    //Double avd = returnAvdiameter().todouble();
    //String^ fac = returnFactor();
    //sum_all_adjustments();
    //String^ adj = returnAdj();
    //calculate = (avd * avd) * depth.todouble() * sg.todouble() * adj.todouble() * fac.todouble();
    //int x = returnDecPlaces(calculate);
    //return String ^ ::number(calculate, 'f', x);
    String^ dummy = "";
    return dummy;
}
String^ GCalc::gem_round_bead_formula(void) {
    //Double calculate;
    //String^ length = returnLength();
    //Double avd = length.todouble();
    //String^ sg = returnSG();
    //String^ fac = returnFactor();
    //Double avdcubed = avd * avd * avd;
    //sum_all_adjustments();
    //String^ adj = returnAdj();
    //calculate = (avdcubed)*sg.todouble() * adj.todouble() * fac.todouble();

    //int x = returnDecPlaces(calculate);
    //return String ^ ::number(calculate, 'f', x);
    String^ dummy = "";
    return dummy;
}
String^ GCalc::gem_lwd_formula(void) {
    //Double calculate;
    //String^ length = returnLength();
    //String^ width = returnWidth();
    //String^ sg = returnSG();
    //String^ depth = returnDepth();
    //String^ fac = returnFactor();
    //sum_all_adjustments();
    //String^ adj = returnAdj();
    //calculate = (length.todouble() * width.todouble()) * depth.todouble() * sg.todouble() * adj.todouble() * fac.todouble();
    //int x = returnDecPlaces(calculate);
    //return String ^ ::number(calculate, 'f', x);
    String^ dummy = "";
    return dummy;
}
String^ GCalc::gem_oval_formula(void) {
    //Double calculate;
    //String^ length = returnLength();
    //String^ width = returnWidth();
    //String^ sg = returnSG();
    //String^ depth = returnDepth();
    //String^ fac = returnFactor();
    //sum_all_adjustments();
    //String^ adj = returnAdj();
    //Double oval_av = (length.todouble() + width.todouble()) / 2;
    //calculate = (oval_av * oval_av) * depth.todouble() * sg.todouble() * adj.todouble() * fac.todouble();
    //int x = returnDecPlaces(calculate);
    //return String ^ ::number(calculate, 'f', x);
    String^ dummy = "";
    return dummy;
}
String^ GCalc::gem_briolette_formula(void) {
    //Double calculate;
    //String^ length = returnLength();
    //String^ width = returnWidth();
    //String^ sg = returnSG();
    ///*String ^ depth=returnDepth();*/
    //String^ fac = returnFactor();
    //sum_all_adjustments();
    //String^ adj = returnAdj();
    //calculate = (length.todouble() * width.todouble()) * width.todouble() * sg.todouble() * adj.todouble() * fac.todouble();
    //int x = returnDecPlaces(calculate);
    //return String ^ ::number(calculate, 'f', x);
    String^ dummy = "";
    return dummy;
}
String^ GCalc::returnWeight(void) {
    //String^ answer, cut_table = "gem_cuts";
    //String^ c = returnCut();
    //int index = 0;
    //QSqlDatabase db = QSqlDatabase::database("MyDB");
    //if (db.open()) {
    //}
    //else {
    //}
    //QSqlQueryModel* model = new QSqlQueryModel();
    //String^ sql;
    //sql = "SELECT cut,factor,xpm,dia FROM `" + cut_table + "` WHERE `cut`='" + c + "'";
    //QSqlQuery* query = new QSqlQuery(db);
    //query->prepare(sql);
    //model->setQuery(*query);
    //if (!query->exec()) {
    //}
    //else {
    //    while (query->next())
    //    {

    //        index = query->value(3).toInt();
    //    }
    String^ dummy = "";
    return dummy;
    }

void GCalc::Initializer(
    String^ cutName,
    String^ gemName,
    String^ fac,
    String^ d1,
    String^ d2,
    String^ dep,
    String^ sg,
    String^ adj,
    String^ gt,
    String^ pv,
    String^ so,

    Boolean isdiamond,
    Boolean interp,
    Boolean recut,
    Boolean roundish,
    Boolean depthisperc) {
    // load all arrays of fancy cut adjustments
    /*load class with GUI values from user*/
    _cutName = cutName; // name of cut
    _gemName = gemName; // name of gem (material)
    _factor = fac; // name of cut
    _d1 = d1; // diameter 1 (could be length)
    _d2 = d2; // diamter 2 (could be width)
    _depth = dep; // depth of stone in millimeters // or percentage
    _sg = sg; //Specific Gravity
    _isDiamond = isdiamond;
    _adj = adj; // user adjustments  
    _interp = interp; // interpolate?
    _recut = recut; // recut?
    _roundish = roundish; // is the cut round necessitating in a different LW formula?
    _depthIsPerc = depthisperc; // is the incoming Depth a represenatation of percentage or mm?

}

String^ GCalc::calculate() {
    Double Length = System::Convert::ToDouble(_d1);
    Double Width = System::Convert::ToDouble(_d2);
    Double Depth = System::Convert::ToDouble(_depth);
    Double SG = System::Convert::ToDouble(_sg);
    Double Factor = System::Convert::ToDouble(_factor);
    Double sum = Math::Round(Length * Width * Depth * Factor, 2);
    System::Windows::Forms::MessageBox::Show(_gemName+"GEM>>d:" + _d1 + "d2: " + _d2 + "dp: " + _depth + "F: " + _factor);
    if (_isDiamond) SG = 1; // the factor laready accounts for specific gravity of 3.52
    return System::Convert::ToString(sum);
    //return L"1.00 ct";"
}