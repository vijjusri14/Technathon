<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Home.aspx.cs" Inherits="Home" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>ParkMyCar</title>
    <link rel="icon" href="Images/iconCar.png" type="image/x-icon"/>
    <link rel="stylesheet" href="StyleSheets/Home.css" />
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <div id="header">
        <h1>Park My Car<img id="iconCar" src="Images/iconCar.png" height="60" width="60"/></h1>
        <p>Now check your slot with a swipe!!</p>
    </div>
        <asp:ImageButton ID="imgbtnCheck" runat="server" Height="50px" ImageUrl="~/Images/iconCar.png" OnClick="imgbtnCheck_Click" style="z-index: 1; left: 627px; top: 245px; position: absolute" ToolTip="Click for Check!!" />
        <div class="selectionbar">
            <asp:Label ID="lblCountry" runat="server" Text="Country:" position="absolute" style="z-index: 1; left: 11px; top: 10px; position: absolute; right: 1016px;"></asp:Label>
            <asp:DropDownList ID="dropCountry" runat="server" position="absolute" style="z-index: 1; left: 73px; top: 10px; position: absolute;width:77px;height:22px; right: 740px;" AutoPostBack="True" OnSelectedIndexChanged="dropCountry_SelectedIndexChanged">
            </asp:DropDownList>
            <asp:Label ID="lblCity" runat="server" Text="City:" position="absolute" style="z-index: 1; left: 230px; top: 10px; position: absolute;"></asp:Label>
            <asp:DropDownList ID="dropCity" runat="server" position="absolute" style="z-index: 1; left: 270px; top: 10px; position: absolute;width:77px;height:22px; right: 733px;" AutoPostBack="True" OnSelectedIndexChanged="dropCity_SelectedIndexChanged">
            </asp:DropDownList>
            <asp:Label ID="lblBuilding" runat="server" Text="Building:" position="absolute" style="z-index: 1; left: 456px; top: 10px; position: absolute;"></asp:Label>
            <asp:DropDownList ID="dropBuilding" runat="server"  position="absolute" style="z-index: 1; left: 516px; top: 10px; position: absolute;width:77px;" AutoPostBack="True" OnSelectedIndexChanged="dropBuilding_SelectedIndexChanged">
            </asp:DropDownList>
            <asp:Label ID="lblTower" runat="server" Text="Tower:" position="absolute" style="z-index: 1; left: 706px; top: 10px; position: absolute;"></asp:Label>
            <asp:DropDownList ID="dropTower" runat="server" position="absolute" style="z-index: 1; left: 758px; top: 10px; position: absolute;width:77px;height:22px;" AutoPostBack="True" OnSelectedIndexChanged="dropTower_SelectedIndexChanged">
            </asp:DropDownList>
            <asp:Label ID="lblfloor" runat="server" Text="Floor:" position="absolute" style="z-index: 1; left: 930px; top: 10px; position: absolute;"></asp:Label>
            <asp:DropDownList ID="dropfloor" runat="server" position="absolute" style="z-index: 1; left: 970px; top: 10px; position: absolute;width:77px;height:22px;" AutoPostBack="True" >
            </asp:DropDownList>
        </div>
        <div id="slotmap" class="slotmap" runat="server">
            <div class="slot1" style="height: 100px; width: 100px; z-index: 1; left: 200px; top: 20px; position: absolute;">
                <img id="a1"  src='Images/AvailableTop.png' style="height: 100px; z-index: 1; left: 0px; top: 0px; position: absolute;"   runat="server" />               
                <img id="na1"  src='Images/NotAvailableTop.png' style="height: 100px; z-index: 1; left: 0px; top: 1px; position: absolute;" runat="server"/>
            </div>
            

            <div class="slot2" style="height: 100px; width: 100px; z-index: 1; right: 200px; top: 20px; position: absolute;">
               <img  id="a2"  runat="server" src='Images/AvailableTop.png' style="height: 100px; z-index: 1; left: 0px; top: 0px; position: absolute;" />
                <img  id="na2" runat="server" src='Images/NotAvailableTop.png' style="height: 100px; z-index: 1; left: 0px; top: 1px; position: absolute;" />
            </div>


                 <div class="slot3" style="height: 100px; width: 100px; z-index: 1; left: 200px; bottom: 20px; position: absolute;">
               <img  id="a3" runat="server" src='Images/AvailableDown.png' style="height: 100px; z-index: 1; left: 0px; top: 0px; position: absolute;" />
                <img  id="na3" runat="server" src='Images/NotAvailableDown.png' style="height: 100px; z-index: 1; left: 0px; top: 1px; position: absolute;" />
            </div>

            <div class="slot4" style="height: 100px; width: 100px; z-index: 1; right: 200px; bottom: 20px; position: absolute;">
               <img  id="a4" runat="server" src='Images/AvailableDown.png' style="height: 100px; z-index: 1; left: 0px; top: 0px; position: absolute;" />
                <img id="na4" runat="server" src='Images/NotAvailableDown.png' style="height: 100px; z-index: 1; left: 0px; top: 1px; position: absolute;" />
            </div>
        </div>
    </div>
    </form>
</body>
</html>
