using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;
using MySql.Data;
using MySql.Data.MySqlClient;
public partial class Home : System.Web.UI.Page
{
    string strConnection = ConfigurationManager.ConnectionStrings["parkmyslotConnectionString"].ConnectionString;

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            countrybind();
            citybind();
            buildingbind();
            towerbind();
            floorbind();
            slotmap.Visible = false;
        }
    }

    protected void countrybind()
    {
        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT DISTINCT COUNTRY_CODE, COUNTRY_DESC FROM tower ORDER BY COUNTRY_DESC";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        dropCountry.DataSource = dt;
        dropCountry.DataBind();
        dropCountry.DataTextField = "COUNTRY_DESC";
        dropCountry.DataValueField = "COUNTRY_CODE";
        dropCountry.DataBind();
        dropCountry.Items.Insert(0, "--Select--");
        con.Close();
    }

    protected void citybind()
    {
        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT DISTINCT CITY_CODE, CITY_DESC FROM tower WHERE COUNTRY_CODE='" + dropCountry.SelectedValue + "' ORDER BY CITY_DESC";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        dropCity.DataSource = dt;
        dropCity.DataBind();
        dropCity.DataTextField = "CITY_DESC";
        dropCity.DataValueField = "CITY_CODE";
        dropCity.DataBind();
        dropCity.Items.Insert(0, "--Select--");
        con.Close();
    }
    protected void buildingbind()
    {
        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT DISTINCT BUILDING_CODE, BUILDING_DESC FROM tower WHERE CITY_CODE='" + dropCity.SelectedValue + "'  ORDER BY BUILDING_DESC";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        dropBuilding.DataSource = dt;
        dropBuilding.DataBind();
        dropBuilding.DataTextField = "BUILDING_DESC";
        dropBuilding.DataValueField ="BUILDING_CODE";
        dropBuilding.DataBind();
        dropBuilding.Items.Insert(0, "--Select--");
        con.Close();
    }
    protected void towerbind()
    {
        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT TOWER_CODE, TOWER_DESC FROM tower WHERE BUILDING_CODE='"+dropBuilding.SelectedValue+"' ORDER BY TOWER_DESC";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        dropTower.DataSource = dt;
        dropTower.DataBind();
        dropTower.DataTextField = "TOWER_DESC";
        dropTower.DataValueField = "TOWER_CODE";
        dropTower.DataBind();
        dropTower.Items.Insert(0, "--Select--");
        con.Close();
    }

    protected void floorbind()
    {
        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT distinct FLOOR_CODE, FLOOR_DESC FROM  tower as t JOIN slot as s on t.TOWER_CODE=s.TOWER_CODE WHERE s.TOWER_CODE='"+dropTower.SelectedValue +"'ORDER BY FLOOR_CODE";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        dropfloor.DataSource = dt;
        dropfloor.DataBind();
        dropfloor.DataTextField = "FLOOR_DESC";
        dropfloor.DataValueField = "FLOOR_CODE";
        dropfloor.DataBind();
        dropfloor.Items.Insert(0, "--Select--");
        con.Close();
    }

    protected void dropCountry_SelectedIndexChanged(object sender, EventArgs e)
    {
        citybind();
    }

    protected void dropCity_SelectedIndexChanged(object sender, EventArgs e)
    {
        buildingbind();
    }

    protected void dropBuilding_SelectedIndexChanged(object sender, EventArgs e)
    {
        towerbind();
    }

    protected void imgbtnCheck_Click(object sender, ImageClickEventArgs e)
    {
        if (dropCountry.SelectedValue == "--Select--" || dropCity.SelectedValue == "--Select--" || dropBuilding.SelectedValue == "--Select--" || dropTower.SelectedValue == "--Select--" || dropfloor.SelectedValue == "--Select--")
        {
            Response.Write("<script>alert('Please Select a valid entry')</script>");
        }
        else
        {
            map();
        }
            
    }

    protected void dropTower_SelectedIndexChanged(object sender, EventArgs e)
    {
        floorbind();
    }

    protected void map()
    {
        

        MySqlConnection con = new MySqlConnection(strConnection);
        string query = "SELECT SLOT_CODE, AVAILABLE FROM tower as t join slot  as s on t.TOWER_CODE=s.TOWER_CODE WHERE s.TOWER_CODE=" + dropTower.SelectedValue + " ORDER BY SLOT_CODE";
        con.Open();
        MySqlDataAdapter adpt = new MySqlDataAdapter(query, con);
        DataTable dt = new DataTable();
        adpt.Fill(dt);
        con.Close();
        
        for (int i = 0; i < dt.Rows.Count; i++)
        {
            
            if (dt.Rows[i][1].ToString() == "YES")
            {
                string idna = "na" + i;
                Control mycontrol = FindControl(idna);
                if (mycontrol != null)
                {
                    mycontrol.Visible = false;
                   
                }
            }

        }
        slotmap.Visible = true;
    }
}