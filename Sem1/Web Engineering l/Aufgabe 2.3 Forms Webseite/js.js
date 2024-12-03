function onload() {
    printEntries();
}


function openNewEntryForm() {
    document.getElementById('new_entry').style.display = 'block';
}

function closeNewEntryForm() {
    document.getElementById('new_entry_form').reset();  
    document.getElementById('new_entry').style.display = 'none';
}

function isLocalStorageFull() {
    try {
        localStorage.setItem('test', 'test');
        localStorage.removeItem('test');
        return false;
    } catch (e) {
        return true;
    }
}

function addEntry(event) {
    event.preventDefault();
    if (isLocalStorageFull()) {
        alert('Local storage is full. Please clear some entries.');
        return;
    }
    let entry = {
        name: document.getElementById('name').value,
        geburtstag: document.getElementById('geburtstag').value,
        email: document.getElementById('email').value,
        telefon: document.getElementById('telefon').value,
        website: document.getElementById('website').value,
        verhältnis: document.getElementById('verhältnis').value,
        lieblingslied: document.getElementById('lieblingslied').value,
        musiklautstärke: document.getElementById('musiklautstärke').value,
        lieblingszeit: document.getElementById('lieblingszeit').value,
        //profilbild: document.getElementById('profilbild').files[0],
        lieblingsfarbe: document.getElementById('lieblingsfarbe').value,
        lieblingstier: document.querySelector('input[name="lieblingstier"]:checked').value,
        lieblingsessen: document.querySelector('input[name="lieblingsessen"]:checked').value,
        lieblingsgetränk: document.querySelector('input[name="lieblingsgetränk"]:checked').value,
        lieblingsgeschichte: document.getElementById('lieblingsgeschichte').value,
        nachricht: document.getElementById('nachricht').value
    };
    console.log(entry);
    storeEntry(entry);
    printEntry(entry);
    document.getElementById('new_entry_form').reset();  
    document.getElementById('new_entry').style.display = 'none';
}

function storeEntry(entry) {
    let entries = loadEntries();
    entries.push(entry);
    localStorage.setItem('entries', JSON.stringify(entries));
}

function printEntry(entry) {
    let container = document.getElementById('entries');
    let div = document.createElement('div');
    div.classList.add('entry');
    //let img = document.createElement('img');
    //img.src = URL.createObjectURL(entry.profilbild);
    //img.alt = entry.name;
    //div.appendChild(img);
    let h2 = document.createElement('h2');
    h2.textContent = entry.name;
    div.appendChild(h2);
    let p = document.createElement('p');
    p.textContent = entry.geburtstag;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.email;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.telefon;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.website;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.verhältnis;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingslied;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.musiklautstärke;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingszeit;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingsfarbe;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingstier;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingsessen;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingsgetränk;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.lieblingsgeschichte;
    div.appendChild(p);
    p = document.createElement('p');
    p.textContent = entry.nachricht;
    div.appendChild(p);
    container.appendChild(div);
}

function loadEntries() {
    let entries = localStorage.getItem('entries');
    if (entries === null) {
        return [];
    }
    return JSON.parse(entries);
}

function printEntries() {
    let entries = loadEntries();
    entries.forEach(entry => {
        printEntry(entry);
    });
}