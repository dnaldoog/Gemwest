using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSconfig
{
    public class SaveSettings
    {
        //https://stackoverflow.com/questions/982354/where-are-the-properties-settings-default-stored

        private string cs_1000_settings = Properties.Settings.Default.entrydecplaces;
        private string cs_carat_result_settings = Properties.Settings.Default.resultdecplaces;
        private string cs_calc = Properties.Settings.Default.calcserialized;
        private Boolean cs_date = Properties.Settings.Default.savedate;
        private Boolean cs_time = Properties.Settings.Default.savetime;


        public string PcsCalc
        {
            get => cs_calc;
            set
            {

                cs_calc = value;
                Properties.Settings.Default.calcserialized = cs_calc;
                Properties.Settings.Default.Save();

            }
        }
        public string Pcs1000
        {
            get => cs_1000_settings;
            set
            {
                cs_1000_settings = value;
                Properties.Settings.Default.entrydecplaces = cs_1000_settings;
                Properties.Settings.Default.Save();

            }
        }
        public string PcsCarat
        {
            get => cs_carat_result_settings;
            set
            {
                cs_carat_result_settings = value;
                Properties.Settings.Default.resultdecplaces = cs_carat_result_settings;
                Properties.Settings.Default.Save();

            }
        }

   
    public Boolean PcsSaveDate
    {
        get => cs_date;
        set
        {
            cs_date = value;
            Properties.Settings.Default.savedate = cs_date;
            Properties.Settings.Default.Save();

        }
    }

        public Boolean PcsSaveTime
        {
            get => cs_time;
            set
            {
                cs_time = value;
                Properties.Settings.Default.savetime = cs_time;
                Properties.Settings.Default.Save();

            }
        }

    }
}
