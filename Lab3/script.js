function edit() {

    var nameK = countryList.currentItem.personData.nameOfKontinent
    var nameG = countryList.currentItem.personData.nameOfGosvo
    var nameS = countryList.currentItem.personData.nameOfState
    var cheell = countryList.currentItem.personData.kindOfCheell

    windowEdit.execute(nameK, nameG, nameS, cheell, countryList.currentIndex)
}

function mouseArea() {

    countryItem.ListView.view.currentIndex = index
    countryItem.forceActiveFocus()
}
