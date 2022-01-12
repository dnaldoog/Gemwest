using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSconfig
{
    class SaveSettings
    {
        //https://stackoverflow.com/questions/982354/where-are-the-properties-settings-default-stored
        //myTextBox.Text = Properties.Settings.Default.;
        private String cs_1000_settings = Properties.Settings.Default.enter1000;
        private bool cs_log_settings = Properties.Settings.Default.logtofile;
 
        public String cs_1000
        {
            get => cs_1000_settings;
            set
            {
                cs_1000_settings = value;
                Properties.Settings.Default.enter1000 = cs_1000_settings;
            }
        }

        public bool cs_log
        {
            get => cs_log_settings;
            set
            {
                cs_log_settings = value;
                Properties.Settings.Default.logtofile = cs_log_settings;
            }
        }
    }

        //Then, after the user edits the value in the options dialog I save it like this:

        //Properties.Settings.Default.MyStringProperty = myTextBox.Text;
        //Properties.Settings.Default.Save();
  
}
