<!DOCTYPE html>
<html lang="en">
  <head>
          <title>WSE Final Project</title>
              <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
      <meta name="robots" content="noarchive">
                                <meta name="CG" content="Search">
        <meta name="SCG" content="cse">
        <meta name="PT" content="Search">
        <meta name="PST" content="Search Results">
        <meta name="PSST" content="">
                <meta name="PS" content="">
                <meta name="ttl" content="">
                                                      
                      
        <link rel="stylesheet" type="text/css" href="http://graphics8.nytimes.com/css/0.1/screen/build/search/styles.css" />
    <script type="text/javascript" src="http://js.nyt.com/js/app/lib/jquery/jquery-1.6.2.min.js"></script>
    <script type="text/javascript" src="http://js.nyt.com/js/app/lib/jquery/jquery-ui-1.8.16.min.js"></script>
    <meta name="viewport" content="initial-scale=1.0, user-scalable=no">
    <meta charset="utf-8">
    <title>Region code biasing (US)</title>
    <script src="https://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false"></script>
    <link rel="stylesheet" type="text/css" href="css/mystyle.css" />
 <script>
var geocoder;
var map;
var query = 'New York';
function initialize() {
  geocoder = new google.maps.Geocoder();
  var mapOptions = {
    zoom: 8,
    mapTypeId: google.maps.MapTypeId.ROADMAP
  }
  map = new google.maps.Map(document.getElementById('map-canvas'), mapOptions);
  codeAddress();
}

function codeAddress() {
  var address = query;
  geocoder.geocode( { 'address': address}, function(results, status) {
    if (status == google.maps.GeocoderStatus.OK) {
      map.setCenter(results[0].geometry.location);
      var marker = new google.maps.Marker({
          map: map,
          position: results[0].geometry.location
      });
    } else {
      alert('Geocode was not successful for the following reason: ' + status);
    }
  });
}

google.maps.event.addDomListener(window, 'load', initialize);

    </script>

        <!--[if IE]>
        <style type="text/css">
            @import url(http://graphics8.nytimes.com/css/0.1/screen/common/ie.css);
        </style>
    <![endif]-->
            <!--[if IE 6]>
        <style type="text/css">
            @import url(http://graphics8.nytimes.com/css/0.1/screen/common/ie6.css);
        </style>
    <![endif]-->
            <!--[if lt IE 9]>
      <script src="http://graphics8.nytimes.com/js/html5shiv.js"></script>
    <![endif]-->
          </head>
      <body>
        
    <a name="top"></a>
    <div id="shell">
            <div id="page" class="tabContent active">
                        <div id="masthead" class="clearfix">
    <div id="branding">
        <a href="http://www.nytimes.com"><img id="NYTLogo" alt="New York Times" src="http://graphics8.nytimes.com/images/misc/nytlogo152x23.gif"></a>
    </div>
        <h2> <a href="/">Final Project</a> </h2>

    <div class="mostPopularSearches" id="mostPopularSearches">
        <div class="tabDropDown">
            <div class="tabDropDownHeader">
                <div class="inset">
                    <h5 class=""><a class="toggleControl">By Xu Deng & Qi Wang</a></h5>
                </div>
            </div><!-- close tabDropDownHeader -->

            <div class="tabDropDownContent">
                <div class="subColumns noBackground">
                    <div class="column firstColumn">
                        <div class="inset"> 
                            <ol class="flush"></ol>
                        </div><!-- close inset -->
                    </div><!-- close column -->

                    <div class="column lastColumn">
                        <div class="inset">
                            <ol class="flush" start="6"></ol>
                        </div><!-- close .inset -->
                    </div><!-- close .column -->
                </div><!-- close .subColumns -->
            </div><!-- close .tabDropDownContent -->

        </div><!-- close .tabDropDown -->
    </div><!-- close .mostPopularSearches -->

</div> <!-- close #masthead --> 
        <div id="searchHeader" class="searchHeader">
    <div class="insetPadded opposingFloatControl wrap">
        <div id="inlineSearchControl" class="searchInputForm inlineSearchControl element1">
            <form class="form-search" action="query.php" method="get">
                <div class="control horizontalControl lastControl">
                    <div class="labelContainer">
                        <label for="newSearchQueryTop">Your Search</label>
                    </div>
                    <div class="fieldContainer containingBlock" id="yourSearch">
                        <input type="text" value="<?=$_GET["key"]?>" name="key" class="newSearchQuery autoSuggestQuery" autocomplete="off">
                        <ol class="autoSuggestQueryResults"></ol>
                        <button class="button" type="submit">Go</button>
                    </div>
                     <div class="fieldContainer containingBlock">
                        <label for="newSearchQueryTop">Near By</label>
                         <input type="text" value="<?=$_GET["location"]?>" name="location" class="" autocomplete="">
                    </div>
                    
                    </div>
                </div>
            </form>
        </div><!-- .inlineSearchControl -->
        <ul class="breadCrumbFilterList element1"></ul>
        <div class="resetFilters element2">
            <a data-refineby="resetFilters" class="searchFilter">Clear All Filters</a>
        </div>
    </div><!-- .inset -->
</div><!-- .searchHeader -->
  
          <div id="main">
                            
          <div class="spanAB wrap">
                          <div class="search ">
                        <div class="abColumn"><!-- open abColumn -->
                                                          <div class="aColumn"><!-- open aColumn -->
                  

      <!--cur: prev:-->
  <div class="columnGroup first">
    
    <div class="columnGroup firstColumn dateFilters">
        <h2>Tag Cloud:<h2>
        <h2>world</h2>
        <h6>against</h6>
      

        <h3>today</h3>
        

<h6>our</h6>
<h2>back</h2>
<h5>state</h5>



<h4>both</h4>
<h1>get<h1>
    <h6>take</h6>
<h4>say</h4>
<h3>5</h3>
<h5>work</h5>
<h3>down</h3>
<h3>these</h3>
<h6>week</h6>
<h2>being</h2>
<h6>part</h6> 
<h2>her</h2> 
<h5>under</h5> 


    </div><!-- .pubTypeFilters -->

 

    <div class="columnGroup imageSearch">
        <ul class="filterList flush">
            <li class="firstItem">
                <a href="http://beta620.nytimes.com/app/image-search/"> <span></span></a>
            </li>
        </ul>
    </div>    
  </div>
                  </div><!-- close aColumn -->
                <div class="bColumn"><!-- open bColumn -->
                  
    
                    <div class="columnGroup first">
        
    
    <div class="sortContainer opposingFloatControl wrap">
        <div class="sortResults element1" id="sortResults">
            <!--<h3 class="horizontalMenuLabel">Sort by:</h3> -->
            <ul class="horizontalMenu piped" >
                <li><a <?if($_GET["type"]=="time_new"){?>class="selectedSort"<?}?> href="query.php?type=time_new&key=<?=$_GET["key"]?>&location=<?=$_GET["location"]?>">Newest</a></li>
                <li><a <?if($_GET["type"]=="time_old"){?>class="selectedSort"<?}?> href="query.php?type=time_old&key=<?=$_GET["key"]?>&location=<?=$_GET["location"]?>">Oldest</a></li>
                <li><a <?if($_GET["type"]!="time_new"&&$_GET["type"]!="time_old" ){?>class="selectedSort"<?}?> href="query.php?key=<?=$_GET["key"]?>&location=<?=$_GET["location"]?>" >Relevance</a></li>
                <li><a href="#map-canvas">Maps</a></li>
            </ul>
        </div>
        <div id="totalResultsCount" class="totalResultsCount element2">
            <p></p>
        </div>
    </div>

    <div class="textAds firstTextAds wrap">
        <div id="SponSearch1">
        </div>
    </div>