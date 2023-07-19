auto NFJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NFJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NFJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NFJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NFJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NFJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NFJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NFJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NFJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NFJJMRDn();
    else
        return vvv.NFJ();
};

auto FJ0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.FJ0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.FJ0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.FJ0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.FJ0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.FJ0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.FJ0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.FJ0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.FJ0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.FJ0JMRDn();
    else
        return vvv.FJ0();
};

auto FJ1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.FJ1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.FJ1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.FJ1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.FJ1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.FJ1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.FJ1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.FJ1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.FJ1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.FJ1JMRDn();
    else
        return vvv.FJ1();
};

auto FJ2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.FJ2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.FJ2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.FJ2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.FJ2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.FJ2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.FJ2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.FJ2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.FJ2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.FJ2JMRDn();
    else
        return vvv.FJ2();
};

auto FJ3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.FJ3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.FJ3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.FJ3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.FJ3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.FJ3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.FJ3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.FJ3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.FJ3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.FJ3JMRDn();
    else
        return vvv.FJ3();
};

auto FJ4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.FJ4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.FJ4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.FJ4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.FJ4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.FJ4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.FJ4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.FJ4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.FJ4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.FJ4JMRDn();
    else
        return vvv.FJ4();
};

auto VMD0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.VMD0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.VMD0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.VMD0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.VMD0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.VMD0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.VMD0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.VMD0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.VMD0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.VMD0JMRDn();
    else
        return vvv.VMD0();
};

auto VMD1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.VMD1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.VMD1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.VMD1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.VMD1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.VMD1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.VMD1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.VMD1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.VMD1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.VMD1JMRDn();
    else
        return vvv.VMD1();
};

auto VMD2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.VMD2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.VMD2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.VMD2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.VMD2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.VMD2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.VMD2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.VMD2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.VMD2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.VMD2JMRDn();
    else
        return vvv.VMD2();
};

auto VMD3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.VMD3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.VMD3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.VMD3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.VMD3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.VMD3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.VMD3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.VMD3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.VMD3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.VMD3JMRDn();
    else
        return vvv.VMD3();
};

auto VMD4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.VMD4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.VMD4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.VMD4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.VMD4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.VMD4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.VMD4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.VMD4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.VMD4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.VMD4JMRDn();
    else
        return vvv.VMD4();
};

auto WMD0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.WMD0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.WMD0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.WMD0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.WMD0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.WMD0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.WMD0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.WMD0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.WMD0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.WMD0JMRDn();
    else
        return vvv.WMD0();
};

auto WMD1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.WMD1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.WMD1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.WMD1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.WMD1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.WMD1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.WMD1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.WMD1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.WMD1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.WMD1JMRDn();
    else
        return vvv.WMD1();
};

auto WMD2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.WMD2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.WMD2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.WMD2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.WMD2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.WMD2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.WMD2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.WMD2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.WMD2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.WMD2JMRDn();
    else
        return vvv.WMD2();
};

auto WMD3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.WMD3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.WMD3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.WMD3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.WMD3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.WMD3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.WMD3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.WMD3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.WMD3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.WMD3JMRDn();
    else
        return vvv.WMD3();
};

auto WMD4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.WMD4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.WMD4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.WMD4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.WMD4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.WMD4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.WMD4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.WMD4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.WMD4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.WMD4JMRDn();
    else
        return vvv.WMD4();
};

auto NQGen0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NQGen0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NQGen0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NQGen0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NQGen0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NQGen0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NQGen0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NQGen0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NQGen0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NQGen0JMRDn();
    else
        return vvv.NQGen0();
};

auto NQGen1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NQGen1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NQGen1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NQGen1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NQGen1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NQGen1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NQGen1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NQGen1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NQGen1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NQGen1JMRDn();
    else
        return vvv.NQGen1();
};

auto NQGen2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NQGen2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NQGen2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NQGen2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NQGen2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NQGen2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NQGen2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NQGen2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NQGen2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NQGen2JMRDn();
    else
        return vvv.NQGen2();
};

auto NQGen3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NQGen3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NQGen3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NQGen3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NQGen3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NQGen3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NQGen3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NQGen3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NQGen3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NQGen3JMRDn();
    else
        return vvv.NQGen3();
};

auto NQGen4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NQGen4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NQGen4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NQGen4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NQGen4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NQGen4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NQGen4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NQGen4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NQGen4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NQGen4JMRDn();
    else
        return vvv.NQGen4();
};

auto NBGen0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NBGen0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NBGen0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NBGen0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NBGen0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NBGen0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NBGen0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NBGen0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NBGen0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NBGen0JMRDn();
    else
        return vvv.NBGen0();
};

auto NBGen1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NBGen1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NBGen1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NBGen1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NBGen1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NBGen1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NBGen1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NBGen1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NBGen1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NBGen1JMRDn();
    else
        return vvv.NBGen1();
};

auto NBGen2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NBGen2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NBGen2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NBGen2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NBGen2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NBGen2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NBGen2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NBGen2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NBGen2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NBGen2JMRDn();
    else
        return vvv.NBGen2();
};

auto NBGen3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NBGen3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NBGen3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NBGen3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NBGen3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NBGen3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NBGen3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NBGen3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NBGen3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NBGen3JMRDn();
    else
        return vvv.NBGen3();
};

auto NBGen4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NBGen4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NBGen4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NBGen4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NBGen4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NBGen4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NBGen4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NBGen4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NBGen4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NBGen4JMRDn();
    else
        return vvv.NBGen4();
};

auto NLGen0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NLGen0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NLGen0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NLGen0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NLGen0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NLGen0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NLGen0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NLGen0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NLGen0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NLGen0JMRDn();
    else
        return vvv.NLGen0();
};

auto NLGen1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NLGen1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NLGen1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NLGen1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NLGen1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NLGen1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NLGen1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NLGen1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NLGen1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NLGen1JMRDn();
    else
        return vvv.NLGen1();
};

auto NLGen2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NLGen2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NLGen2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NLGen2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NLGen2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NLGen2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NLGen2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NLGen2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NLGen2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NLGen2JMRDn();
    else
        return vvv.NLGen2();
};

auto NLGen3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NLGen3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NLGen3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NLGen3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NLGen3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NLGen3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NLGen3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NLGen3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NLGen3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NLGen3JMRDn();
    else
        return vvv.NLGen3();
};

auto NLGen4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NLGen4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NLGen4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NLGen4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NLGen4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NLGen4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NLGen4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NLGen4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NLGen4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NLGen4JMRDn();
    else
        return vvv.NLGen4();
};

auto NiFJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NiFJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NiFJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NiFJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NiFJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NiFJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NiFJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NiFJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NiFJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NiFJJMRDn();
    else
        return vvv.NiFJ();
};

auto iFJ0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iFJ0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iFJ0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iFJ0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iFJ0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iFJ0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iFJ0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iFJ0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iFJ0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iFJ0JMRDn();
    else
        return vvv.iFJ0();
};

auto iFJ1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iFJ1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iFJ1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iFJ1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iFJ1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iFJ1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iFJ1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iFJ1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iFJ1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iFJ1JMRDn();
    else
        return vvv.iFJ1();
};

auto iFJ2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iFJ2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iFJ2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iFJ2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iFJ2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iFJ2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iFJ2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iFJ2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iFJ2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iFJ2JMRDn();
    else
        return vvv.iFJ2();
};

auto iFJ3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iFJ3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iFJ3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iFJ3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iFJ3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iFJ3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iFJ3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iFJ3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iFJ3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iFJ3JMRDn();
    else
        return vvv.iFJ3();
};

auto iFJ4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iFJ4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iFJ4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iFJ4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iFJ4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iFJ4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iFJ4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iFJ4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iFJ4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iFJ4JMRDn();
    else
        return vvv.iFJ4();
};

auto iVMD0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iVMD0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iVMD0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iVMD0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iVMD0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iVMD0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iVMD0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iVMD0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iVMD0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iVMD0JMRDn();
    else
        return vvv.iVMD0();
};

auto iVMD1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iVMD1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iVMD1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iVMD1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iVMD1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iVMD1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iVMD1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iVMD1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iVMD1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iVMD1JMRDn();
    else
        return vvv.iVMD1();
};

auto iVMD2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iVMD2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iVMD2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iVMD2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iVMD2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iVMD2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iVMD2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iVMD2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iVMD2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iVMD2JMRDn();
    else
        return vvv.iVMD2();
};

auto iVMD3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iVMD3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iVMD3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iVMD3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iVMD3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iVMD3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iVMD3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iVMD3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iVMD3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iVMD3JMRDn();
    else
        return vvv.iVMD3();
};

auto iVMD4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iVMD4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iVMD4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iVMD4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iVMD4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iVMD4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iVMD4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iVMD4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iVMD4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iVMD4JMRDn();
    else
        return vvv.iVMD4();
};

auto iWMD0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iWMD0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iWMD0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iWMD0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iWMD0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iWMD0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iWMD0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iWMD0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iWMD0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iWMD0JMRDn();
    else
        return vvv.iWMD0();
};

auto iWMD1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iWMD1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iWMD1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iWMD1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iWMD1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iWMD1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iWMD1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iWMD1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iWMD1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iWMD1JMRDn();
    else
        return vvv.iWMD1();
};

auto iWMD2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iWMD2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iWMD2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iWMD2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iWMD2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iWMD2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iWMD2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iWMD2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iWMD2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iWMD2JMRDn();
    else
        return vvv.iWMD2();
};

auto iWMD3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iWMD3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iWMD3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iWMD3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iWMD3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iWMD3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iWMD3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iWMD3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iWMD3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iWMD3JMRDn();
    else
        return vvv.iWMD3();
};

auto iWMD4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.iWMD4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.iWMD4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.iWMD4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.iWMD4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.iWMD4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.iWMD4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.iWMD4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.iWMD4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.iWMD4JMRDn();
    else
        return vvv.iWMD4();
};

auto MET = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.MET();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.METJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.METJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.METJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.METJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.METJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.METJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.METJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.METJMRDn();
    else
        return vvv.MET();
};

auto Nu = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.Nu();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NuJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NuJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NuJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NuJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NuJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NuJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NuJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NuJMRDn();
    else
        return vvv.Nu();
};

auto NJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NJJMRDn();
    else
        return vvv.NJ();
};

auto NbLoose = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NbLoose();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NbLooseJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NbLooseJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NbLooseJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NbLooseJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NbLooseJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NbLooseJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NbLooseJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NbLooseJMRDn();
    else
        return vvv.NbLoose();
};

auto NbMedium = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NbMedium();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NbMediumJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NbMediumJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NbMediumJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NbMediumJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NbMediumJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NbMediumJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NbMediumJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NbMediumJMRDn();
    else
        return vvv.NbMedium();
};

auto NbTight = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NbTight();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NbTightJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NbTightJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NbTightJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NbTightJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NbTightJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NbTightJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NbTightJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NbTightJMRDn();
    else
        return vvv.NbTight();
};

auto NoORNbLoose = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NoORNbLoose();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NoORNbLooseJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NoORNbLooseJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NoORNbLooseJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NoORNbLooseJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NoORNbLooseJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NoORNbLooseJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NoORNbLooseJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NoORNbLooseJMRDn();
    else
        return vvv.NoORNbLoose();
};

auto NoORNbMedium = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NoORNbMedium();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NoORNbMediumJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NoORNbMediumJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NoORNbMediumJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NoORNbMediumJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NoORNbMediumJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NoORNbMediumJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NoORNbMediumJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NoORNbMediumJMRDn();
    else
        return vvv.NoORNbMedium();
};

auto NoORNbTight = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.NoORNbTight();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.NoORNbTightJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.NoORNbTightJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.NoORNbTightJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.NoORNbTightJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.NoORNbTightJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.NoORNbTightJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.NoORNbTightJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.NoORNbTightJMRDn();
    else
        return vvv.NoORNbTight();
};

auto J0 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.J0();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.J0JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.J0JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.J0JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.J0JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.J0JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.J0JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.J0JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.J0JMRDn();
    else
        return vvv.J0();
};

auto J1 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.J1();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.J1JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.J1JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.J1JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.J1JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.J1JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.J1JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.J1JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.J1JMRDn();
    else
        return vvv.J1();
};

auto J2 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.J2();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.J2JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.J2JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.J2JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.J2JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.J2JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.J2JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.J2JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.J2JMRDn();
    else
        return vvv.J2();
};

auto J3 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.J3();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.J3JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.J3JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.J3JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.J3JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.J3JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.J3JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.J3JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.J3JMRDn();
    else
        return vvv.J3();
};

auto J4 = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.J4();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.J4JESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.J4JESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.J4JERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.J4JERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.J4JMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.J4JMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.J4JMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.J4JMRDn();
    else
        return vvv.J4();
};

auto MVVX = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.MVVX();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.MVVXJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.MVVXJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.MVVXJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.MVVXJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.MVVXJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.MVVXJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.MVVXJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.MVVXJMRDn();
    else
        return vvv.MVVX();
};

auto PtVVX = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.PtVVX();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.PtVVXJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.PtVVXJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.PtVVXJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.PtVVXJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.PtVVXJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.PtVVXJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.PtVVXJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.PtVVXJMRDn();
    else
        return vvv.PtVVX();
};

auto HT = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.HT();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.HTJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.HTJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.HTJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.HTJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.HTJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.HTJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.HTJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.HTJMRDn();
    else
        return vvv.HT();
};

auto HTJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.HTJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.HTJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.HTJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.HTJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.HTJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.HTJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.HTJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.HTJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.HTJJMRDn();
    else
        return vvv.HTJ();
};

auto HTFJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.HTFJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.HTFJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.HTFJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.HTFJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.HTFJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.HTFJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.HTFJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.HTFJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.HTFJJMRDn();
    else
        return vvv.HTFJ();
};

auto SumPtFJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.SumPtFJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.SumPtFJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.SumPtFJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.SumPtFJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.SumPtFJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.SumPtFJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.SumPtFJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.SumPtFJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.SumPtFJJMRDn();
    else
        return vvv.SumPtFJ();
};

auto SumPtJ = [&](TString syst_name="Nominal")
{
    if (syst_name.EqualTo("Nominal"))
        return vvv.SumPtJ();
    else if (syst_name.EqualTo("JESUp"))
        return vvv.SumPtJJESUp();
    else if (syst_name.EqualTo("JESDn"))
        return vvv.SumPtJJESDn();
    else if (syst_name.EqualTo("JERUp"))
        return vvv.SumPtJJERUp();
    else if (syst_name.EqualTo("JERDn"))
        return vvv.SumPtJJERDn();
    else if (syst_name.EqualTo("JMSUp"))
        return vvv.SumPtJJMSUp();
    else if (syst_name.EqualTo("JMSDn"))
        return vvv.SumPtJJMSDn();
    else if (syst_name.EqualTo("JMRUp"))
        return vvv.SumPtJJMRUp();
    else if (syst_name.EqualTo("JMRDn"))
        return vvv.SumPtJJMRDn();
    else
        return vvv.SumPtJ();
};

auto isData = [&]()
{
    return vvv.isData();
};

auto run = [&]()
{
    return vvv.run();
};

auto evt = [&]()
{
    return vvv.evt();
};

auto genWeight = [&]()
{
    return vvv.genWeight();
};

auto wgt = [&]()
{
    return vvv.wgt();
};

auto LHEReweightingWeight = [&]()
{
    return vvv.LHEReweightingWeight();
};

auto trigger = [&]()
{
    return vvv.trigger();
};

auto is0Lep = [&]()
{
    return vvv.is0Lep();
};

auto is1Lep = [&]()
{
    return vvv.is1Lep();
};

auto Lep = [&]()
{
    return vvv.Lep();
};

auto LepFlav = [&]()
{
    return vvv.LepFlav();
};

auto GenV0 = [&]()
{
    return vvv.GenV0();
};

auto GenV1 = [&]()
{
    return vvv.GenV1();
};

auto GenV2 = [&]()
{
    return vvv.GenV2();
};

auto isHad0 = [&]()
{
    return vvv.isHad0();
};

auto isHad1 = [&]()
{
    return vvv.isHad1();
};

auto isHad2 = [&]()
{
    return vvv.isHad2();
};

auto GenF00 = [&]()
{
    return vvv.GenF00();
};

auto GenF01 = [&]()
{
    return vvv.GenF01();
};

auto GenF10 = [&]()
{
    return vvv.GenF10();
};

auto GenF11 = [&]()
{
    return vvv.GenF11();
};

auto GenF20 = [&]()
{
    return vvv.GenF20();
};

auto GenF21 = [&]()
{
    return vvv.GenF21();
};

auto prefireWgt = [&]()
{
    if (ana.syst_name.EqualTo("prefireWgtUp"))
        return vvv.prefireWgtUp();
    else if (ana.syst_name.EqualTo("prefireWgtDn"))
        return vvv.prefireWgtDn();
    else
        return vvv.prefireWgt();
};

auto puWgt = [&]()
{
    if (ana.syst_name.EqualTo("puWgtUp"))
        return vvv.puWgtUp();
    else if (ana.syst_name.EqualTo("puWgtDn"))
        return vvv.puWgtDn();
    else
        return vvv.puWgt();
};

auto trigWgt = [&]()
{
    if (ana.syst_name.EqualTo("trigWgtUp"))
        return vvv.trigWgtUp();
    else if (ana.syst_name.EqualTo("trigWgtDn"))
        return vvv.trigWgtDn();
    else
        return vvv.trigWgt();
};

